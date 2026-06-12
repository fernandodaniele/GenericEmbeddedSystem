En este punto estableceremos la comunicación entre la PC y el microcontrolador. Se plantea que el software sea el encargado de solicitar datos o funciones al firmware. Para poder establecer una comunicación clara, elaborar una lista de comandos para las distintas posibilidades. Las funciones mínimas que se deben considerar en la comunicación son las siguientes:
Comando enviado desde PC ||	Acción ||	Comando de respuesta
“TR”	Leer sensor de temperatura (o correspondiente)	“OK” + Valor temperatura
“LA”	Activar led	“OK”            || "OK"
“LA”	Desactivar led	“OK”        || "OK"
“LR”	Leer estado led	“OK” mas estado led “1” o “0”
“UA” "+" Nombre "+" Contraseña	Agregar usuario y contraseña ||	“OK”
“UM” + Nombre + Contraseña nueva	Modifica contraseña	“OK”
“UL”	Lista todos los usuarios	“OK” + Nombre de cada usuario + “END”

Además de esto, se puede agregar las funciones que se consideren necesarias. Previo a comenzar la programación, agregar un archivo readme al proyecto que documente con la lista completa de estos comandos (puede no ser definitiva y cambiar a medida que avance el desarrollo.
Una vez realizado esto de manera grupal, cada desarrollador realizará lo siguiente:
•	Dev-1: Software: Agregar la funcionalidad para permitir enviar los comandos por puerto serie, teniendo en cuenta las respuestas que espera, o el dato que debe enviar a continuación.
•	Dev-2: Firmware: Agregar la funcionalidad para que pueda recibir los “comandos” por el puerto serie. En base al comando recibido, se debe responder de la manera acordada y realizar la función establecida (activar/desactivar actuador, modificar datos de usuario, etc)
•	Dev-3:Firmware: Crear una estructura para manejo el manejo de los datos de usuario, como el nombre y la clave de acceso. Cuando un usuario ingrese su clave, se debe activar el relé o led durante 5 segundos. 
