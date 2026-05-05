1- Crear un repositorio privado en GitHub el cual contendrá el proyecto que desarrollaremos.
2- Clonar (uno de los 3 desarrolladores)
3- Agregar una carpeta llamada SoftwareC. Dentro de ella crear las carpetas src, inc y el archivo CMakeLists.txt.
4- Crear la carpeta documentacion y agregar el diagrama del proyecto.
5- Crear los archivos main.c, menu.c y menu.h en las carpetas correspondientes. Agregar la función main(), y las directivas correspondientes para incluir archivos .h y para evitar múltiples inclusiones.
6- Comentar el código usando el formato doxygen. A partir de este punto, todo nuevo archivo o función que creemos, asi como también cualquier cambio de gran importancia, deben estar documentados mediante este formato.
7- Guardar cambios, hacer commit y sincronizar con GitHub.
8- Crear la rama Development


 
9- A partir de acá, crear ramas por cada desarrollador:
•	Dev-1: deberá crear en el archivo main.c un superloop. En la sección de configuración, llamar a la función void IniciarMenu(void). En el bucle infinito, leer la entrada de teclado, si se presiona Escape, salir del programa, si se presiona otra tecla pasar el carácter correspondiente como parámetro a la función void ActualizarMenu(char);
•	Dev-2: deberá crear los prototipos de void IniciarMenu(void) y void ActualizarMenu(char) en menu.h y definir dichas funciones en menu.c. IniciarMenu debe mostrar un mensaje que diga “Esta es la sección de configuración” y ActualizarMenu(char) debe mostrar un mensaje que diga “La letra presionada fue” y mostrar la letra recibida como parámetro.
•	Dev-3: Asegurarse de que estamos en la rama Dev-3. Cerrar carpeta si estamos dentro de VSC. Crear proyecto con PlatformIO para el ESP32-S3, llamarlo Firmware y guardarlo dentro de la carpeta del proyecto.
   
9- Una vez finalizada su parte, cada desarrollador deberá realizar commit (poner como mensaje ProjectStart-Dev1 2 o 3 según corresponda) e integrar sus cambios en la rama main mediante PULL REQUEST
 
10- Configurar GitHub Copilot y crear el respectivo archivo de contexto. Utilizar el modo agente para crear un pipeline que permita la compilación automática en GitHub cada vez que se haga un Push sobre cualquier rama.

11-	Publicar y verificar el correcto funcionamiento.