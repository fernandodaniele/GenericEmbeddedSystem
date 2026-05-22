# Instrucciones para GitHub Copilot

## Propósito del repositorio
Este proyecto es un sistema embebido con dos partes principales:
- `Firmware/`: código de firmware en C/C++ para hardware embebido, usando PlatformIO
- `SoftwareC/`: aplicación de software en C con CMake para funciones de usuario
- `Documentation/`: documentos de actividades y diagramas funcionales

## Enfoque principal
Copilot debe ayudar con:
- mantener la coherencia con la estructura de archivos existente
- Mantener un estilo de código sencillo y legible en C/C++

## Reglas importantes
- No modificar archivos generados ni artefactos de compilación.
- No proponer bibliotecas externas no usadas por el proyecto actual.
- El código nuevo debe ser legible y mantener un estilo de C sencillo.
- Utilizar comentarios en español cuando sea necesario explicar la lógica del estado o menú.
- Los comentarios deben estar en formato doxygen para facilitar la generación de documentación futura.

## Archivos clave
- `Firmware/src/main.cpp`: entrada principal del firmware
- `Firmware/include/` y `Firmware/src/`: lugar para el código de teclado y menú del firmware
- `SoftwareC/src/main.c`: entrada principal del software
- `SoftwareC/inc/menu.h`: interfaz del menú de software
- `Documentation/`: documentación de actividad y diagramas de estado

## Evitar
- No tocar `SoftwareC/build/`.
- No incluir en el repositorio archivos de compilación (`*.o`, `*.elf`, `*.bin`, `*.hex`, `*.map`).
- No modificar `Documentation/` salvo para agregar diagramas o documentación necesaria.

## Contexto adicional
Este repositorio es de un proyecto dinamico con 3 desarrolladores trabajando en paralelo. Cada uno tiene asignada una parte específica del proyecto. En la documentacion se agregan nuevas actividades a medida que avanza el proyecto. Copilot debe sugerir cambios acordes a estos objetivos y ayudar a mantener el proyecto organizado.