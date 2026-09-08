#include "../include/voltage.h"

int voltageInputPin; // Pin analogico de entrada de voltaje.
int motorPin;

void initVoltageInput(int pin)
{
    voltageInputPin = pin;


}

void initMotor(int pin){
    motorPin = pin;
}

float readVoltage()
{
    uint16_t sensorValue;
    sensorValue = analogRead(voltageInputPin); // Leer el valor de la entrada analogica.

    uint8_t output = sensorValue/4; // Guardar el valor leido para la salida.
    analogWrite(motorPin, output); // Salida PWM.
    dacWrite(DAC1, output); // Salida DAC.
    
    float voltage = sensorValue * (3.3 / 4095.0); // Convertir la lectura ADC a voltios.

    return voltage;
}
