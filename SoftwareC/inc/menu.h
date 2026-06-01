/**
 * @file menu.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-05-05
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef MENU_H
#define MENU_H

#include <stdint.h>

/**
 * @brief Funcion para inicializar el menu de usuario
 * 
 */
void menuInit(void);

/**
 * @brief 
 * 
 * @param letter 
 */
void menuUpdate(char inputChar);

/**
 * @brief Screen states for the menu.
 */
typedef enum {
    MAIN_MENU,
    SENSOR_MENU,
    LED_MENU,
    USER_MENU,
} screen_t;

#endif // MENU_H