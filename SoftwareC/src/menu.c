/**
 * @file menu.c
 * @author tu nombre (tu@dominio.com)
 * @brief Implementación del menú para la aplicación SoftwareC.
 * @version 0.1
 * @date 2026-05-05
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "../inc/menu.h"
#include "../inc/serial.h"

static void showMainMenu(void);
static void showSensorMenu(void);
static void showLedMenu(void);
static void showUserMenu(void);
static void resetMenu(void);

screen_t currentScreen;
uint8_t option = 0;

void menuInit(void){
    currentScreen = MAIN_MENU;
}

void menuUpdate(char inputChar){
    (void)inputChar;

    switch (currentScreen) {
        case MAIN_MENU: {
            showMainMenu();
            if (scanf("%hhu", &option) != 1) {
                option = 0;
            }
            switch (option) {
                case 1: {
                    printf("Menú de Sensores\n");
                    currentScreen = SENSOR_MENU;
                } break;
                case 2: {
                    printf("Menú de LED\n");
                    currentScreen = LED_MENU;
                } break;
                case 3: {
                    printf("Menú de sensor\n");
                    currentScreen = SENSOR_MENU;
                } break;
                case 0: {
                    currentScreen = MAIN_MENU;
                    exit(0);
                } break;
                default: {
                    // opción inválida, permanece en el menú principal
                } break;
            }
        } break;

        case SENSOR_MENU: {
            showSensorMenu();
            if (scanf("%hhu", &option) != 1) {
                option = 0;
            }
            switch (option) {
                case 1: {
                    printf("Leyendo voltaje...\n");
                    sendCommand('V');
                    Sleep(1000);
                    
                } break;
                case 0: {
                    printf("Volviendo al menú principal...\n");
                    currentScreen = MAIN_MENU;
                } break;
                default: {
                    printf("Opción inválida. Intente de nuevo.\n");
                } break;
            }
        } break;

        case LED_MENU: {
            showLedMenu();
            if (scanf("%hhu", &option) != 1) {
                option = 0;
            }
            switch (option) {
                case 1: {
                    printf("Encendiendo LED...\n");
                    if(sendCommand('E')){
                        printf("Error enviando comando\n");
                        break;
                    }
                    Sleep(1000);
                    if(readResponse()){
                        printf("Error leyendo respuesta\n");
                        break;
                    }
                } break;
                case 2: {
                    printf("Apagando LED...\n");
                    if(sendCommand('A')){
                        printf("Error enviando comando\n");
                        break;
                    }
                    Sleep(1000);
                    if(readResponse()){
                        printf("Error leyendo respuesta\n");
                        break;
                    }
                } break;
                case 0: {
                    printf("Volviendo al menú principal...\n");
                    currentScreen = MAIN_MENU;
                } break;
                default: {
                    printf("Opción inválida. Intente de nuevo.\n");
                } break;
            }
        } break;

        case USER_MENU: {
            showUserMenu();
            if (scanf("%hhu", &option) != 1) {
                option = 0;
            }
            switch (option) {
                case 1: {
                    printf("Agregar usuario\n");
                } break;
                case 2: {
                    printf("Modificar usuario\n");
                } break;
                case 3: {
                    printf("Eliminar usuario\n");
                } break;
                case 0: {
                    printf("Volviendo al menú principal...\n");
                    currentScreen = MAIN_MENU;
                } break;
                default: {
                    printf("Opción inválida. Intente de nuevo.\n");
                } break;
            }
        } break;

        default: {
            resetMenu();
        } break;
    }
}

static void showMainMenu(void) {
    printf("\n--- Menú Principal ---\n");
    printf("1 - Menú de Sensores\n");
    printf("2 - Menú de LED\n");
    printf("3 - Menú de Usuarios\n");
    printf("0 - Salir\n");
    printf("Seleccione una opción: ");
}

static void showSensorMenu(void) {
    printf("\n--- Menú de Sensores ---\n");
    printf("1 - Leer voltaje\n");
    printf("0 - Volver al menú principal\n");
    printf("Seleccione una opción: ");
}

static void showLedMenu(void) {
    printf("\n--- Menú de LED ---\n");
    printf("1 - Encender LED\n");
    printf("2 - Apagar LED\n");
    printf("0 - Volver al menú principal\n");
    printf("Seleccione una opción: ");
}

static void showUserMenu(void) {
    printf("\n--- Menú de Usuarios ---\n");
    printf("1 - Agregar usuario\n");
    printf("2 - Modificar usuario\n");
    printf("3 - Eliminar usuario\n");
    printf("0 - Volver al menú principal\n");
    printf("Seleccione una opción: ");
}

static void resetMenu(void) {
    currentScreen = MAIN_MENU;
}