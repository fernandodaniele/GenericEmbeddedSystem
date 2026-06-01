#include "menu.h"

typedef enum {
    MENU_MAIN,
    MENU_SENSOR,
    MENU_USERS
} EstadoMenu_t;

void menuUpdate (char button) {
    static EstadoMenu_t estado_menu = MENU_MAIN;

    // Si no se presionó ninguna button, salimos rápido sin bloquear nada
    if (button == '\0') {
        return; 
    }

    // Si hay una button válida, la procesamos según el estado del menú
    switch (estado_menu) {
        case MENU_MAIN:
            if (button == '1') { // Ej: '1' para ir a configuración
                // Cambiar al menú de sensores
                estado_menu = MENU_SENSOR;
            }
            break;

        case MENU_SENSOR:
            if (button == '*') { // Ej: '*' para volver
                // Volver al menú principal
                estado_menu = MENU_MAIN;
            }
            break;

        case MENU_USERS:
            if (button == '*') { // Ej: '*' para volver
                // Volver al menú principal
                estado_menu = MENU_MAIN;
            }
            break;

        default:
             // En caso de un estado no reconocido, volvemos al menú principal
            estado_menu = MENU_MAIN;
            break;
    }
}