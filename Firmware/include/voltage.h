#ifndef VOLTAGE_H
#define VOLTAGE_H

#include <Arduino.h>
// En caso de usar una libreria externa para la entrada analogica,
// incluirla aqui.

/*************************/

/** @brief Inicializa la entrada analogica de voltaje.
 */
void initVoltageInput(int pin);

/** @brief Lee el voltaje de la entrada analogica.
 *  @return Voltaje medido en voltios.
 */
float readVoltage();


#endif // VOLTAGE_H