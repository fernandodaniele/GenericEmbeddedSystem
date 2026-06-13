//================== Inclusiones ==========================
#include <Windows.h>
#include "../inc/serial.h"
#include "../inc/rs232.h"

//================== Definiciones ==========================
#define LONG_BUFFER 4096

//================== Configuraciones ==========================
int COMPort=3;             //Número de puerto. 6 es para el COM7 en windows
int bauds=115200;            //Velocidad en baudios
char mode[]={'8','N','1',0}; // 8 bits de datos, no paridad, 1 bit de parada

unsigned char bufferRecepcion[LONG_BUFFER];
int nBytes;

int serialInit(int newCOM){
    COMPort = newCOM;
    if(RS232_OpenComport(COMPort, bauds, mode, 0)) //Prueba abrir el puerto, devuelve 1 en caso de error
    {
        printf("No se puede abrir el puerto COM\n");
        return(1); //Error
    }
    return(0); //OK
}

int sendCommand(char command){
    //Envía un byte sobre el puerto COM elegido
    return RS232_SendByte(COMPort, command);
}

int readResponse(){
    //Lee los datos almacenados en el buffer del puerto COM y los guarda en bufferRecepcion
    //Devuelve la cantidad de bytes leídos
    nBytes = RS232_PollComport(COMPort, bufferRecepcion, LONG_BUFFER-1);

    if(nBytes > 0)
    {
        bufferRecepcion[nBytes] = 0;   // Poner un NULL al final del string
        printf("Se recibieron %i bytes: %s\n", nBytes, (char *)bufferRecepcion);
        return 0; //OK
    }
    return 1; //Error
}    
    