/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-05-05
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "../inc/menu.h"
#include "../inc/serial.h"

#define PORT_COM    6-1

int main(void) {
    char letter = ' ';
    int key = 0;

    serialInit(PORT_COM);
    // Seccion de configuracion/inicializacion
    menuInit();

    // Loop infinito
    while (1) {
        //falta agregar un printf
        key = _getch();
        if (key == 27) {
            // Si se presiona Escape, salir del programa
            break;
        }

        if (key == EOF) {
            continue;
        }
        letter = (char)key;
        // Pasar el carácter correspondiente como parámetro a la función void menuUpdate(char)
        menuUpdate(letter);
    }

    return 0;
}