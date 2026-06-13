En este punto estableceremos la comunicación entre la PC y el microcontrolador. Se plantea que el software sea el encargado de solicitar datos o funciones al firmware. 
Desde la rama Develop (grupal):
Software: Agregar la librería rs232 para el manejo del puerto serie de PC y crear un módulo para el manejo de la comunicación serie (ej.: serial.c/.h)
Firmware: Crear un módulo para el manejo de la comunicación serie (ej.: uart.c/.h)
Verificar que compile bien, hacer commit y push y de ahí cada dev debe crear su propia rama
Dev1- Software:
1- Crear la función de inicialización del puerto serie
2- Crear la función para el envío de un comando
3- Crear una función que sirva para leer e imprimir los datos obtenidos del puerto serie.
4- Agregar en el menu el envio de comandos para encender y apagar el led. Cuando el usuario ingrese a este menu, se debe enviar el comando correspondiente (“E” o “A”) y esperar la respuesta del ESP32/Arduino. Cuando la reciba imprimir.
5- Hacer commit, y agregar cambios a la rama develop
Dev2- Firmware:
1- Crear un módulo para el manejo de la comunicación serie (ej.: uart.c/.h)
2- Crear la función de inicialización del puerto serie
3- Crear una función que lea el puerto serie. En caso se recibir el comando valido, realizar la acción correspondiente (encender/apagar led) y responder “OK”. En caso contrario responder con error.
4- Hacer commit, y agregar cambios a la rama develop
Una vez listas las dos partes, probar que la comunicación funcione correctamente. Al entrar al menu de test, PC debería enviar el comando, el ESP32 responder, y PC imprimir la respuesta.
