#include <Arduino.h>
#include "menu.h"
#include "keypad.h"
#include "uart.h"

void setup() {
    keypadInit();
}

void loop() {
    char key = keypadUpdate();
    menuUpdate(key);
    delay(100); // Agrega un pequeño retraso para evitar lecturas rápidas del teclado
}
