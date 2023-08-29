# Gamemode Base - Roleplay [MySql]
### How to install?

- Download the [database]((https://github.com/KaizerHind/GamemodeBase_MySQL/blob/master/Database/dbserver.sql)), go to [Xampp](http://localhost/phpmyadmin/server_import.php) and create a new clean database, then import the new one.

- Download the [gamemode](https://github.com/KaizerHind/Gamemode-Base/archive/refs/heads/1.0.zip) and extract the content to the path you want.

- Lastly, remember to configure the [mysql.ini](https://github.com/KaizerHind/GamemodeBase_MySQL/blob/master/mysql.ini) file, which contains the database configuration.

**Note Important:**

**Credits to:**

    KaizerHind - Developer.
    
    D13G0 - Doubts about MySql.
    
    r99t - Hash password solution and Doubts about MySql.
    
    Galasso - Hash password solution.
    
    DeusExMachina - Solution SP/SD
---

### Dependencies
- [SA-MP 0.3.7-R2 Windows Server](http://files.sa-mp.com/samp037_svr_R2-1-1_win32.zip)

- [Crashdetect](https://github.com/Zeex/samp-plugin-crashdetect)

- [MySQL-r41](https://github.com/pBlueG/SA-MP-MySQL)

- [streamer](https://github.com/samp-incognito/samp-streamer-plugin/releases/tag/v2.9.5)

- [sscanf](https://github.com/maddinat0r/sscanf)

- [YSI-Includes(v5.06.1932)](https://github.com/pawn-lang/YSI-Includes/releases/tag/v5.06.1932)

- [Discord Connector](https://github.com/maddinat0r/samp-discord-connector)

- [Anticheat Nex-AC](https://github.com/NexiusTailer/Nex-AC/archive/refs/heads/master.zip)

- [fixes](https://github.com/pawn-lang/sa-mp-fixes/blob/Branch_YSF/fixes.inc)

---

# • **Español:**

 Desarrolle esta gamemode con la unica intencion de compartirla con las personas que deseen iniciar un proyecto en SA-MP, como bien aprender programacion modular. La gamemode contiene sistemas basicos de rol, esta hecha para desarrolladores Juniors que deseen aprender y crear su propio servidor.

 - **Acerca de los sistemas:**
 - [x] Registro e Ingreso al Servidor.
 - [x] Sistema de muerte y spawn en el Hospital.
 - [x] Certificacion de Rol.
 - [x] Comandos de rol basicos. `(me, do, gritar, blit, susurro, intentar)`
 - [x] Comando de acentos. `(Decido no hacerle guardado de Mysql)`
 - [x] Comando de curar la salud.
 - [x] Sistema de "Evasión de rol". `(Tras morir y desconectarte, el servidor te enviara un mensaje, diciendo que evadiste un rol, claramente deben desarrollar el sistema por su cuenta)`
 - [x] Reduccion de vida al morir. `(Tras tener un accidente, tu vida se reducira hasta volver a morir y hacer spawn en el hospital)`
 - [x] Registro de mensajes via Servidor > Discord. 

**Contenido Gamemode:**

    |— gamemodes
    
    |—— index - .pwn - Archivo Pwn.
    
    |——— content\ - Contenido del Servidor. (Modulo principal)
    
    |———— content\cmds - Comandos del jugador y administrativos.
    
    |———— content\designs - Mapas y Textdraws.
    
    |———— content\includes - Includes modificados y conexion con sistemas.
    
    |———— content\server - Variables, macros, conexiones y otros.
    
    |———— content\systems - Sistemas desarrollados y conectados con el modulo principal.
---
# • **English:**

I developed this gamemode with the sole intention of sharing it with people who want to start a project in SA-MP, as well as learn modular programming. The gamemode contains basic role-playing systems, it is made for Junior developers who want to learn and create their own server.

- **About systems:**  
- [x] Registration and Login to the Server.
- [x] System of death and respawn in the Hospital.
- [x] Role Certification.
- [x] Basic role commands. `(me, do, yell, blit, whisper, try)`
- [x] Accent Command. `(I decide not to save from Mysql)`
- [x] Command heal health.
- [x] System 'Role avoidance'. `(After you die and log out, the server will send you a message saying you bypassed a role, clearly they should develop the system on their own)`
- [x] Life reduction in case of death. `(After having an accident, your life will be reduced until you die again and appear in the hospital)`
- [x] Message log through Server > Discord.