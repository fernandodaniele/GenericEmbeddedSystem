#include "keypad.h"

#include <Arduino.h>
#include <stdint.h>

// Definición de los Estados de la Máquina
typedef enum {
    KEYPAD_STATE_IDLE,
    KEYPAD_STATE_SCAN_C0,
    KEYPAD_STATE_SCAN_C1,
    KEYPAD_STATE_SCAN_C2,
    KEYPAD_STATE_SCAN_C3,
    KEYPAD_STATE_DEBOUNCE
} KeypadState_t;

// Pines asignados para el teclado en la placa ESP32-S3
static const uint8_t keypad_col_pins[4] = {2, 4, 5, 18};
static const uint8_t keypad_row_pins[4] = {19, 20, 21, 22};

// Matriz de caracteres del teclado 4x4
static const char keypad_map[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

void escribir_columnas(uint8_t c0, uint8_t c1, uint8_t c2, uint8_t c3) {
    digitalWrite(keypad_col_pins[0], c0 ? HIGH : LOW);
    digitalWrite(keypad_col_pins[1], c1 ? HIGH : LOW);
    digitalWrite(keypad_col_pins[2], c2 ? HIGH : LOW);
    digitalWrite(keypad_col_pins[3], c3 ? HIGH : LOW);
}

uint8_t leer_filas(void) {
    uint8_t rows = 0;

    rows |= (digitalRead(keypad_row_pins[0]) == LOW) ? 0x01 : 0x00;
    rows |= (digitalRead(keypad_row_pins[1]) == LOW) ? 0x02 : 0x00;
    rows |= (digitalRead(keypad_row_pins[2]) == LOW) ? 0x04 : 0x00;
    rows |= (digitalRead(keypad_row_pins[3]) == LOW) ? 0x08 : 0x00;

    // Convertimos la lectura a máscara de filas con HIGH = no pulsado, LOW = pulsado
    return (rows == 0) ? 0x0F : (uint8_t)(0x0F & ~rows);
}
// ----------------------------------------------------------------------------------------------------

// Función que procesa el estado de la fila presionada y devuelve el índice (0 a 3)
static int8_t get_row_index(uint8_t rows) {
    if ((rows & 0x01) == 0) return 0; // R0 conectada a GND
    if ((rows & 0x02) == 0) return 1; // R1 conectada a GND
    if ((rows & 0x04) == 0) return 2; // R2 conectada a GND
    if ((rows & 0x08) == 0) return 3; // R3 conectada a GND
    return -1; // Ninguna fila presionada
}

void keypadInit(void) {
    // Inicializa el teclado para que las columnas queden inactivas (HIGH)
    escribir_columnas(1, 1, 1, 1);
}

// MÁQUINA DE ESTADOS PRINCIPAL
char keypadUpdate(void) {
    static KeypadState_t current_state = KEYPAD_STATE_IDLE;
    static int8_t row_index = -1;
    static int8_t col_index = -1;
    char pressed_key = '\0'; // '\0' significa ninguna tecla nueva
    uint8_t row_state;

    switch (current_state) {
        case KEYPAD_STATE_IDLE:
            // Ponemos todas las columnas en LOW para detectar CUALQUIER pulsación
            escribir_columnas(0, 0, 0, 0);
            row_state = leer_filas();

            if (row_state != 0x0F) { // Si alguna fila cambió a LOW
                current_state = KEYPAD_STATE_SCAN_C0; // Empezamos el escaneo secuencial
            }
            break;

        case KEYPAD_STATE_SCAN_C0:
            escribir_columnas(0, 1, 1, 1); // Activamos solo Columna 0
            row_state = leer_filas();
            row_index = get_row_index(row_state);

            if (row_index != -1) {
                col_index = 0;
                current_state = KEYPAD_STATE_DEBOUNCE;
            } else {
                current_state = KEYPAD_STATE_SCAN_C1; // Siguiente columna
            }
            break;

        case KEYPAD_STATE_SCAN_C1:
            escribir_columnas(1, 0, 1, 1); // Activamos solo Columna 1
            row_state = leer_filas();
            row_index = get_row_index(row_state);

            if (row_index != -1) {
                col_index = 1;
                current_state = KEYPAD_STATE_DEBOUNCE;
            } else {
                current_state = KEYPAD_STATE_SCAN_C2;
            }
            break;

        case KEYPAD_STATE_SCAN_C2:
            escribir_columnas(1, 1, 0, 1); // Activamos solo Columna 2
            row_state = leer_filas();
            row_index = get_row_index(row_state);

            if (row_index != -1) {
                col_index = 2;
                current_state = KEYPAD_STATE_DEBOUNCE;
            } else {
                current_state = KEYPAD_STATE_SCAN_C3;
            }
            break;

        case KEYPAD_STATE_SCAN_C3:
            escribir_columnas(1, 1, 1, 0); // Activamos solo Columna 3
            row_state = leer_filas();
            row_index = get_row_index(row_state);

            if (row_index != -1) {
                col_index = 3;
                current_state = KEYPAD_STATE_DEBOUNCE;
            } else {
                current_state = KEYPAD_STATE_IDLE; // Falsa alarma, volvemos a IDLE
            }
            break;

        case KEYPAD_STATE_DEBOUNCE:
            // Estado de espera para el antirrebote y liberación de la tecla
            // Configuramos la columna detectada en LOW y las demás en HIGH
            escribir_columnas(
                (col_index == 0) ? 0 : 1,
                (col_index == 1) ? 0 : 1,
                (col_index == 2) ? 0 : 1,
                (col_index == 3) ? 0 : 1
            );

            row_state = leer_filas();

            // Si las filas vuelven a estar en HIGH (0x0F), significa que se soltó la tecla
            if (get_row_index(row_state) == -1) {
                // Registramos la tecla que fue presionada con éxito
                pressed_key = keypad_map[row_index][col_index];
                current_state = KEYPAD_STATE_IDLE; // Regresa al estado inicial
            }
            break;

        default:
            current_state = KEYPAD_STATE_IDLE;
            break;
    }

    return pressed_key; // Devuelve el caracter detectado o '\0' si no hay nada nuevo
}