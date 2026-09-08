#include "../include/voltage.h"

int voltageInputPin; // Pin analogico de entrada de voltaje.
int motorPin;

void initVoltageInput(int pin){
    voltageInputPin = pin;
}

void initMotor(int pin){
    motorPin = pin;
}

float readVoltage(){
    uint16_t sensorValue;
    sensorValue = analogRead(voltageInputPin); // Leer el valor de la entrada analogica.

    uint8_t output = sensorValue * (255.0 / 4095.0); // Guardar el valor leido para la salida.
    analogWrite(motorPin, output); // Salida PWM.
    //dacWrite(DAC1, output); // Salida DAC. No disponible en Arduino Uno y ESP32 S3, si en ESP32 clasico.
    
    float voltage = sensorValue * (3.3 / 4095.0); // Convertir la lectura ADC a voltios.

    return voltage;
}
