//================== Inclusiones =============================
#include "../include/uart.h"
#include "../include/temperature.h"

//================== Definiciones =============================
#define LED LED_BUILTIN

//================== Variables globales =============================
String receivedData;

void uartInit() {
    Serial.begin(115200);   // Inicializa el puerto serie a 115200 baudios.
    pinMode(LED,OUTPUT);
    digitalWrite(LED, LOW );
}

void uartReadCommand(){
    if(Serial.available()>0)      // Lee solo cuando hay datos disponibles en el buffer.
    {
        receivedData = Serial.readString();

        if(receivedData == "E")   // El comando E enciende el LED y A lo apaga.
        {
            Serial.print("K");
            digitalWrite(LED, HIGH);
        }
        else if(receivedData == "A")
        {
            Serial.print("K");
            digitalWrite(LED, LOW);
        }
        else if(receivedData == "V")
        {
            Serial.print("V");
            float voltage = readVoltage();
            Serial.print(voltage);
        }
        else
        {
            Serial.print("Comando no reconocido");
        }
    }
}