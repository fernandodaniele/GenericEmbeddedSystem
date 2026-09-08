#include <Arduino.h>
#include "menu.h"
#include "keypad.h"
#include "uart.h"
#include "../include/voltage.h"

#define VOLTAGE_INPUT_PIN A0 // Pin analogico de entrada de voltaje.

void setup() {
    uartInit();
    keypadInit();
    initVoltageInput(VOLTAGE_INPUT_PIN); // Inicializa la entrada de voltaje en el pin definido.
}

void loop() {
    char key = keypadUpdate();
    menuUpdate(key);
    uartReadCommand();
    delay(100); // Agrega un pequeño retraso para evitar lecturas rápidas del teclado
}
