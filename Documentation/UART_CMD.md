### Tabla de Comandos PC-ESP32

| Comando enviado desde PC | Acción | Comando de respuesta del ESP32 |
| :---    | :--- | :--- |
| `“TR”` | Leer sensor de temperatura (o correspondiente) | `“OK”` + Valor temperatura |
| `“LA” + “1”` | Activar led | `“OK”` |
| ``“LA” + “0”` | Desactivar led | `“OK”` |
| `“LR”` | Leer estado led | `“OK”` + estado led (`“1”` o `“0”`) |
| `“UA”` + Nombre + Contraseña | Agregar usuario y contraseña | `“OK”` |
| `“UM”` + Nombre + Contraseña nueva | Modifica contraseña | `“OK”` |
| `“UL”` | Lista todos los usuarios | `“OK”` + Nombre de cada usuario + `“END”` |