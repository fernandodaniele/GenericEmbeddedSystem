//================== Inclusiones ==========================
#include "../inc/serial.h"
#include "../inc/rs232.h"

//================== Definiciones ==========================
#define LONG_BUFFER 4096

//================== Configuraciones ==========================
int COMPort=3;             // Numero de puerto. 6 corresponde al COM7 en Windows.
int bauds=115200;            // Velocidad en baudios.
char mode[]={'8','N','1',0}; // 8 bits de datos, sin paridad y 1 bit de parada.

unsigned char receiveBuffer[LONG_BUFFER];
int bytesRead;

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
    // Envia un byte por el puerto serie seleccionado.
    return RS232_SendByte(COMPort, command);
}

int readResponse(){
    // Lee los datos del puerto serie y los guarda en receiveBuffer.
    // Devuelve cero si se recibieron datos y uno si ocurrio un error.
    bytesRead = RS232_PollComport(COMPort, receiveBuffer, LONG_BUFFER-1);

    if(bytesRead > 0)
    {
        receiveBuffer[bytesRead] = 0;   // Terminar la respuesta como cadena.
        printf("Se recibieron %i bytes: %s\n", bytesRead, (char *)receiveBuffer);

        // La respuesta de voltaje comienza con V y contiene el valor en voltios.

        // receiveBuffer[0] = "K" o "V".
        // Desde receiveBuffer[0] hasta receiveBuffer[bytesRead] esta el valor.

        return 0; //OK
    }
    return 1; //Error
}    
    