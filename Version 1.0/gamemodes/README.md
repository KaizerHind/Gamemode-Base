# Auburn Roleplay - v1.0

### Changes 1.0 / 27-07

- Configuracion de Discord. (implementacion de envio de mensajes de Servidor a Discord)
- Se repararon peque�os errores en Mysql. (sincronizacion y guardado, personaje, salud)
- Se a�adio un Test de Rol. (Extraido de deugub; Hecho por Edinson Walker)
- Se a�adio un peque�o detalle el cual muestra el total de Aciertos al Examen de Rol.

### Changes 1.0 / 28-07
- Se corrigio un error el cual no permitia el ingreso de usuarios con el mismo nombre.

### Changes 1.0 / 29-07
- Se a�adio una pregunta de seleccion de Ciudad al Registro de cuenta.

### Changes 1.0 / 02-08
- Se corrigieron varios errores con respecto al Registro e Inicio de Sesion con respecto al ingreso de jugadores.

### Changes 1.0 / 03-08
- Varios errores de MySql fueron reparados.
- Se implemento el Anticheat Nex-Ac. (Lang Spanish)
- Se implemento el guardado de 'Cuenta creada' y 'Ultima sesion'.
- Algunas variables, textos y entre otras cosas fueron modificadas.
- Los nombres de la DB fueron cambiados.

### Changes 1.0 / 04-08
- La 'Rule 39' del NexAC(nex-ac_settings.cfg) fue desactivada temporalmente. (expulsa al jugador por extra�a razon al iniciar)
- Algunas variables, textos y entre otras cosas fueron modificadas.
- La funcion 'ShowPlayerDialog' fue eliminada por completo de 'pRegister', pasando a ser reemplazada por las funciones de './content/includes/dialogs'. (dialog_show)

### Changes 1.0 / 05-08
- Algunas variables, textos y entre otras cosas fueron modificadas.
- Se corrigieron un peque�o error en Mysql y el NexAc, el cual expulsaba al jugador al responder los dialogos. (r99t - Kai)

### Changes 1.0 / 07-08
- La 'Rule 39' del NexAC(nex-ac_settings.cfg) fue habilitada nuevamente. (expulsaba al jugador por extra�a razon al morir)
- Se corrigio casi por completo el sistema de Spawn y Muerte, debido a que el Anticheat expulsaba al jugador una vez que moria.
- Se implemento una funcion de reduccion de vida para cuando el jugador muera, lo envie al hospital.
- Se corrigio un problema el cual hacia que el jugador muriera dos veces, enviando asi dos mensajes al tiempo.

### Changes 1.0 / 23-08
- Se fixeo un peque�o fallo el cual no spawneaba al jugador una vez que re-ingresaba al servidor luego de morir o de manera normal.
- Se a�adio una columna(Died) en la DB, para cargar el estado de muerte del jugador(0 o 1).

## ULTIMA ACTUALIZACION 23-08 | NO HABRA MAS ACTUALIZACIONES, A MENOS QUE SEA PARA REPARAR ALGUN ERROR.

## Gracias especiales a r99t por el Soporte y demas personas en los creditos.

 **Content:**

    |� gamemodes
    |�� index - .pwn
    |��� content\           - Content of the server.
    |���� content\cmds      - Commands player & admins
    |���� content\designs   - Maps and Textdraws.
    |���� content\includes  - Includes modified and connected with systems.
    |���� content\server    - Vars, macros, connections and others.
    |���� content\systems   - Systems developed and connected to the gamemode.
    
----