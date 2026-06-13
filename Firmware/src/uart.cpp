//================== Inclusiones =============================
#include "../include/uart.h"

//================== Definiciones =============================
#define LED LED_BUILTIN

//================== Variables globales =============================
String datosRecibidos;

void uartInit() {
    Serial.begin(115200);   //Inicializa el puerto  serie a 115200 baudios
    pinMode(LED,OUTPUT);
    digitalWrite(LED, LOW );
}

void uartReadCommand(){
    if(Serial.available()>0)      //Procede a la lectura solo si hay datos disponibles en el buffer
    {
        datosRecibidos = Serial.readString();

        if(datosRecibidos == "E")   //Si el comando recibido es E enciende el led, si es A lo apaga
        {
            Serial.print("OK");
            digitalWrite(LED, HIGH);
        }
        else if(datosRecibidos == "A")
        {
            Serial.print("OK");
            digitalWrite(LED, LOW);
        }
        else
        {
            Serial.print("Comando no reconocido");
        }
    }
}