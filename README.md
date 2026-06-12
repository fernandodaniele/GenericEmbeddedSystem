# GenericEmbeddedSystem
Proyecto para aprender a trabajar en el desarrollo de sistemas embebidos de manera grupal y autonoma.

## Comunicación UART
La comunicación entre PC y microcontrolador utiliza comandos serie.

- `TR` : Leer sensor de temperatura.
- `LA1` : Activar LED.
- `LA0` : Desactivar LED.
- `LR` : Leer estado del LED.
- `UA<nombre>+<clave>` : Agregar usuario y contraseña.
- `UM<nombre>+<nueva_clave>` : Modificar contraseña de usuario.
- `UL` : Listar usuarios.
- `LOGIN<nombre>+<clave>` : Validar usuario y activar LED por 5 segundos.

Más detalles en `Documentation/UART_CMD.md`.
