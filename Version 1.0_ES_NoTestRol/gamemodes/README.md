# Project Roleplay - v1.0

### Changes 1.0 / 27-07

- Configuracion de Discord. (implementacion de envio de mensajes de Servidor a Discord)
- Se repararon pequeños errores en Mysql. (sincronizacion y guardado, personaje, salud)
- Se añadio un Test de Rol. (Extraido de deugub; Hecho por Edinson Walker)
- Se añadio un pequeño detalle el cual muestra el total de Aciertos al Examen de Rol.

### Changes 1.0 / 28-07
- Se corrigio un error el cual no permitia el ingreso de usuarios con el mismo nombre.

### Changes 1.0 / 29-07
- Se añadio una pregunta de seleccion de Ciudad al Registro de cuenta.

### Changes 1.0 / 02-08
- Se corrigieron varios errores con respecto al Registro e Inicio de Sesion con respecto al ingreso de jugadores.

### Changes 1.0 / 03-08
- Varios errores de MySql fueron reparados.
- Se implemento el Anticheat Nex-Ac. (Lang Spanish)
- Se implemento el guardado de 'Cuenta creada' y 'Ultima sesion'.
- Algunas variables, textos y entre otras cosas fueron modificadas.
- Los nombres de la DB fueron cambiados.

### Changes 1.0 / 04-08
- La 'Rule 39' del NexAC(nex-ac_settings.cfg) fue desactivada temporalmente. (expulsa al jugador por extraña razon al iniciar)
- Algunas variables, textos y entre otras cosas fueron modificadas.
- La funcion 'ShowPlayerDialog' fue eliminada por completo de 'pRegister', pasando a ser reemplazada por las funciones de './content/includes/dialogs'. (dialog_show)

### Changes 1.0 / 05-08
- Algunas variables, textos y entre otras cosas fueron modificadas.
- Se corrigieron un pequeño error en Mysql y el NexAc, el cual expulsaba al jugador al responder los dialogos. (r99t - Kai)

### Changes 1.0 / 07-08
- La 'Rule 39' del NexAC(nex-ac_settings.cfg) fue habilitada nuevamente. (expulsaba al jugador por extraña razon al morir)
- Se corrigio casi por completo el sistema de Spawn y Muerte, debido a que el Anticheat expulsaba al jugador una vez que moria.
- Se implemento una funcion de reduccion de vida para cuando el jugador muera, lo envie al hospital.
- Se corrigio un problema el cual hacia que el jugador muriera dos veces, enviando asi dos mensajes al tiempo.

### Changes 1.0 / 23-08
- Se fixeo un pequeño fallo el cual no spawneaba al jugador una vez que re-ingresaba al servidor luego de morir o de manera normal.
- Se añadio una columna(Died) en la DB, para cargar el estado de muerte del jugador(0 o 1).
- Se implementaron comandos basicos de rol. (b, me, do, susurrar, gritar, intentar)

### Changes 1.0 / 26-08
- Se actualizo el include 'fixes.inc', al mismo tiempo se realizaron pequeños cambios en variables, debido a sus advertencias.
- Se comento/deshabilito una linea codigo generada por 'fixes'.inc el cual generaba la siguiente advertencia «function is deprecated(symbol "CST_SHA256_PassHash") Use BCrypt or better for hashing passwords», lo cual es innecesario actualizar.

### Changes 1.0 / 28-08
- El Include fixes fue actualizado debido a una incompatibilidad.
- Se añadieron un par de funciones en AccountLoaded y ClearDiedAnims, las cuales cumplen lo siguiente:
* En 'AccountLoaded' detectamos si el jugador al re-conectar esta herido(en este caso, si quiteo estando muerto), en ese caso, al haber "evadido", la variable de muerte es limpiada y se "envia a jail". (En realidad no se envia a ningun lado, esto debe ser programado por quien tenga el gamemode en sus manos)

* La funcion 'ClearDiedAnims' la llamaremos una vez que el jugador haya muerto y aparecido en el Hospital, este Timer lo que hara es limpiar la variable, para asi una vez que vuelva a morir, no suceda algun bug y el Anticheat no expulse al jugador.

- Se soluciono un problema el cual no almacenaba la variable de muerte y bugueaba el guardado/seteado del Score.
- Se implemento el Textdraw-Error-Command, el cual tal como dice su nombre, al ejecutar un comando erroneo, lanzara un sonido + un Textdraw el cual se ocultara.
---

 **Content:**

    |— gamemodes
    |—— index - .pwn
    |——— content\           - Content of the server.
    |———— content\cmds      - Commands player & admins
    |———— content\designs   - Maps and Textdraws.
    |———— content\includes  - Includes modified and connected with systems.
    |———— content\server    - Vars, macros, connections and others.
    |———— content\systems   - Systems developed and connected to the gamemode.
    
----