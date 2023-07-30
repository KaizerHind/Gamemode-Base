
# Gamemode Base - Roleplay [MySql]

### How to install?

 - Download the [database]((https://github.com/KaizerHind/GamemodeBase_MySQL/blob/master/Database/dbserver.sql)), go to [Xampp](http://localhost/phpmyadmin/server_import.php) and create a new clean database, then import the new one.

 - Download the [gamemode](https://github.com/KaizerHind/Gamemode-Base/archive/refs/heads/1.0.zip) and extract the content to the path you want.

 - Lastly, remember to configure the [mysql.ini](https://github.com/KaizerHind/GamemodeBase_MySQL/blob/master/mysql.ini) file, which contains the database configuration.

  **Note Important:** 

    Credits to:
    
    KaizerHind - Developer.
    D13G0 - Doubts about MySql.
    r99t - Hash password solution and Doubts about MySql.
    Galasso - Hash password solution.

---

### Dependencies

- [SA-MP 0.3.7-R2 Windows Server](http://files.sa-mp.com/samp037_svr_R2-1-1_win32.zip)

- [Crashdetect](https://github.com/Zeex/samp-plugin-crashdetect)

- [streamer](https://github.com/samp-incognito/samp-streamer-plugin)

- [sscaf](https://github.com/maddinat0r/sscanf)

- [MySQL-r41](https://github.com/pBlueG/SA-MP-MySQL)

- [YSI-Includes(v5.06.1932)](https://github.com/pawn-lang/YSI-Includes/releases/tag/v5.06.1932)

---

# • **Español:**

Esta gamemode es una base la cual contiene unicamente un sistema de Registro Basico(Test de Rol, Registro, Ingreso y otros datos). La gamemode fue desarrollada de manera **'Modular'**, por lo que parte del codigo esta distribuido en **.gamemode/content**, cabe resaltar que si alguien le añade un sistema de muebles o algo relacionado a edicion de objetos, y deben utilizar los siguientes parametros **OnPlayerPickUpDynamicPickup, OnPlayerSelectDynamicObject,OnPlayerEditDynamicObject**, deberan añadir esto en index.pwn, en el modulo **system**, puede ser debajo del modulo **roltest**.

**Contenido:**

    |— gamemodes
    |—— index - .pwn - File Pwn.
    |——— content\ - Contenido del Servidor. (Modulo principal)
    |———— content\cmds - Comandos del jugador y administrativos.
    |———— content\designs - Mapas y Textdraws.
    |———— content\includes - Includes modificados y conexion con sistemas.
    |———— content\server - Variables, macros, conexiones y otros.
    |———— content\systems - Sistemas desarrollados y conectados con el modulo principal.

# • **English:**

This gamemode is a base which contains only a Basic Registration system(**Proof of Role**, **Registration** and **Login** and other data). The gamemode was developed in a **'Modular'** way, so part of the code is distributed in **.gamemode/content**, it should be noted that if someone adds a furniture system or something related to object editing, and they must use the following parameters **OnPlayerPickUpDynamicPickup , OnPlayerSelectDynamicObject, OnPlayerEditDynamicObject,** you should add this in index.pwn, in the **system** module, below the **roltest** module.

**Content:**

    |— gamemodes
    |—— index - .pwn
    |——— content\ - Content of the server.
    |———— content\cmds - Commands player & admins
    |———— content\designs - Maps and Textdraws.
    |———— content\includes - Includes modified and connected with systems.
    |———— content\server - Vars, macros, connections and others.
    |———— content\systems - Systems developed and connected to the gamemode.

----
