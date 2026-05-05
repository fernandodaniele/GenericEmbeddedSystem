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

int main(){
    char letter = ' ';
    //Seccion de configuracion/inicializacion
    menuInit();

    //Loop infinito
    while(1)
    {
        //Leer entrada de teclado

        //si se presiona Escape
        //salir del programa (break)
        
        //si se presiona otra tecla
        //pasar el carácter correspondiente como parámetro a la función void menuUpdate(char);
        menuUpdate(letter);
    }

    return 0;
}