public OnGameModeInit()
{
	/* ======== [ Configuración general ] ======== */
	ShowPlayerMarkers(PLAYER_MARKERS_MODE_GLOBAL);
	ShowNameTags(1);
	EnableStuntBonusForAll(0);
	DisableInteriorEnterExits();
	ManualVehicleEngineAndLights();

    SetGameModeText(SERVER_MODE);
	SendRconCommand("hostname "SERVER_NAME"");
    SendRconCommand("mapname "SERVER_MAP"");
	SendRconCommand("language "SERVER_LANG"");
	SendRconCommand("password "SERVER_RCON"");
    SendRconCommand("weburl "SERVER_DISCORD"");
	SendRconCommand("gravity "SERVER_GRAVITY"");

    /* ############### ini Config File.  ############### */
    DB = mysql_connect_file("mysql.ini");
    if (mysql_errno(DB) == 0) {
        SendOnLineEmbedMessage(DCHANNEL_LOG, "La Conexion con la **Base de Datos** y **Discord** ha sido Exitosa - [MySQL]");
        print("La Conexion con la DB ha sido Exitosa - [MySQL]\n");
    } else {
        print("La Conexion con la DB ha Fallado - [MySQL]");
        SendRconCommand("exit");
    }
	/* ################################################# */
	/* ## A Partir de aqui puedes agregar codigo ## */
	/* ############################################ */


	/* ############### DON TOUCH ############### */
	#if defined pregister_OnGameModeInit
		return pregister_OnGameModeInit();
	#else
		return 1;
	#endif
}

#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit pregister_OnGameModeInit
#if defined pregister_OnGameModeInit
	forward pregister_OnGameModeInit();
#endif


public OnGameModeExit()
{
    foreach(new a: Player){SavePlayer(a);}
    mysql_close(DB);
	/* ############### DON TOUCH ############### */
	#if defined pregister_OnGameModeExit
		return pregister_OnGameModeExit();
	#else
		return 0;
	#endif
}

#if defined _ALS_OnGameModeExit
	#undef OnGameModeExit
#else
	#define _ALS_OnGameModeExit
#endif

#define OnGameModeExit pregister_OnGameModeExit
#if defined pregister_OnGameModeExit
	forward pregister_OnGameModeExit();
#endif

public OnPlayerRequestClass(playerid, classid)
{
	StartLoginCamera(playerid);
	/* ############### DON TOUCH ############### */
	#if defined pregister_OnPlayerRequestClass
		return pregister_OnPlayerRequestClass(playerid, classid);
	#else
		return 0;
	#endif
}

#if defined _ALS_OnPlayerRequestClass
	#undef OnPlayerRequestClass
#else
	#define _ALS_OnPlayerRequestClass
#endif

#define OnPlayerRequestClass pregister_OnPlayerRequestClass
#if defined pregister_OnPlayerRequestClass
	forward pregister_OnPlayerRequestClass(playerid, classid);
#endif

public OnPlayerConnect(playerid)
{
	if(playerid >= MAX_PLAYERS)
	{
	    SendClientMessage(playerid, HCOL_WHITE, "Actualmente solo se admiten "COL_WHITE"50 usuarios"COL_WHITE".\nSi deseas ingresar y no puedes, reporta esto en Discord.");
		Kick(playerid);
		return 1;
	}

	new last_name[24], NamePosition;

	GetPlayerName(playerid, last_name, 24);
	NamePosition = strfind(last_name, "_");
	
	if(!NamePosition || NamePosition < 1 || NamePosition > (strlen(last_name)-2) || InvalidCharacterName(last_name))
	{//
		strcat(gbl_log, ""COL_WHITE"Al parecer has ingresado con un nombre invalido al Servidor.\n", sizeof(gbl_log));
		strcat(gbl_log, ""COL_WHITE"En "COL_SERVER""SERVER_PROJECT""COL_WHITE" no se permiten nombres como el que llevas, ya que\n", sizeof(gbl_log));
		strcat(gbl_log, ""COL_WHITE"el Servidor carece de un "COL_SERVER"Rol Medio"COL_WHITE", por lo tanto debes modificar tu nombre.\n", sizeof(gbl_log));
		strcat(gbl_log, ""COL_WHITE"\nEl uso correcto es "COL_SERVER"Nombre_Apellido"COL_WHITE"; Te recomendamos reiniciar una vez\nque hayas cambiado tu nombre.\n", sizeof(gbl_log));
		Dialog_Show(playerid, 9999, DIALOG_STYLE_MSGBOX, ""COL_SERVER""SERVER_NAME" "COL_WHITE"- ¡Oops! Al parecer hay un error.", gbl_log, "Aceptar", "");

		/* Discord: discord.inc */
		new log[250];
		format(log, sizeof(log), "(( `%s` ha sido expulsado automaticamente por el Servidor.\n\n**Razon:** `Nombre incorrecto`. ))", PlayerTemp(playerid));
		ConvertDiscordText(log),
		SendGetOutEmbedMessage(DCHANNEL_LOG, log);

		SetTimerEx("ReasonKick", 1000, false, "i", playerid);
		SetTimerEx("DialogKick", 2000, false, "i", playerid);
		return 1;
	}

	SetPlayerColor(playerid, HCOL_TMPGRAY);
	ValidateUppercase(playerid, last_name, NamePosition);
	PreloadAnimLibs(playerid);
	ShowServerNameTD(playerid);

	mysql_format(DB, global_str, sizeof global_str, "SELECT * FROM users WHERE Name = '%e'  LIMIT 1", PlayerName(playerid));
	mysql_query(DB, global_str);
	mysql_tquery(DB, global_str, "OnPlayerDataCheck", "d", playerid);

	/* ############### DON TOUCH ############### */
	#if defined pregister_OnPlayerConnect
		return pregister_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect pregister_OnPlayerConnect
#if defined pregister_OnPlayerConnect
	forward pregister_OnPlayerConnect(playerid);
#endif

public OnPlayerDisconnect(playerid, reason)
{
	if (GetPVarInt(playerid, "Logueado") == 1)
	{
	 	SetPVarInt(playerid, "Logueado", 1);

		if(playerid == INVALID_PLAYER_ID) return 0;
		switch(reason)
		{
			case 0:
			{
				format(gbl_log, sizeof(gbl_log), "(( `%s(%d)` se desconectó por crash o Timed-out. ))", PlayerTemp(playerid), playerid);
			}
			case 1:
			{
				format(gbl_log, sizeof(gbl_log), "(( `%s(%d)` se desconectó voluntariamente. ))", PlayerName(playerid), playerid);		 
			}
			case 2:
			{
				format(gbl_log, sizeof(gbl_log), "(( `%s(%d)` se desconectó. `(Fue kickeado o baneado)` ))", PlayerTemp(playerid), playerid);
			}
		}
		ProxDetector(20.0, playerid, gbl_log, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE);
		
		/* Discord: discord.inc */
		ConvertDiscordText(gbl_log),
		SendGetOutEmbedMessage(DCHANNEL_LOG, gbl_log);

		SavePlayer(playerid);
	 	return 1;
	}

    #if defined pregister_OnPlayerDisconnect
        return pregister_OnPlayerDisconnect(playerid, reason);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect pregister_OnPlayerDisconnect
#if defined pregister_OnPlayerDisconnect
    forward pregister_OnPlayerDisconnect(playerid, reason);
#endif

forward OnPlayerDataCheck(playerid); public OnPlayerDataCheck(playerid){
	if (IsPlayerNPC(playerid)) return Kick(playerid);
	if (GetPVarInt(playerid, "Logueado"))
	{
	 	Kick(playerid);
	 	return 1;
	}

	if(cache_num_rows() > 0){
		new hash[64 + 1];
		ClearChat(playerid, 100);
		StartLoginCamera(playerid);
		cache_get_value_name(0, "Password", hash);
		format(PlayerData[playerid][jPass], 65, "%s", hash);
		
		format(glb_str2, sizeof(glb_str2), "\n\n\t\t"COL_WHITE"¡Bienvenido de nuevo %s!.\n__________________________________________________________\nTu ultima conexion fue el: ><\n\nIngresa tu contraseña para entrar al Servidor.\n\nSino eres el propietario de dicha cuenta, te\ninvitamos a reloguear con otro nombre que este disponible.", PlayerName(playerid));
		ShowPlayerDialog(playerid, dLogin, DIALOG_STYLE_PASSWORD, mHeader, glb_str2, ""COL_WHITE"Aceptar", ""COL_WHITE"Salir");
	}else{

		ClearChat(playerid, 100);
		StartLoginCamera(playerid);
		/* Discord: discord.inc */
		format(gbl_log, sizeof(gbl_log), "(( `%s` ha ingresado al Servidor y comenzara a realizar el Examen de Rol. **[Part 1/3]** ))",  PlayerTemp(playerid));
		ConvertDiscordText(gbl_log);
		SendJoinEmbedMessage(DCHANNEL_LOG, gbl_log);
		
		new str_wlc[500];
		format(str_wlc, sizeof(str_wlc), ""COL_WHITE"Que tal "COL_SERVER"%s"COL_WHITE".\n\nAntes que nada, gracias por elegirnos como Comunidad.\nA Continuacion realizaras un Examen de Rol con un minimo de  6 preguntas las\ncuales deberas responder todas de manera correcta.\n\nEn caso de fallar 5 de las 6 preguntas, deberas realizar elexamen nuevamente.\n\n¡Buena suerte en el Examen!", PlayerTemp(playerid));
		ShowPlayerDialog(playerid, dExamen, DIALOG_STYLE_MSGBOX, mHeader, str_wlc, ""COL_WHITE"Aceptar", "");
	}
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	new VarAge = strval(inputtext);

	switch(dialogid){
		case dExamen:{InitPlayerRoleTest(playerid);}
		case dLogin:
		{
			if(response)
			{
				new megahash[64 + 1];
				SHA256_PassHash(inputtext, "123h1h23hh", megahash, 64);
				if(strcmp(PlayerData[playerid][jPass], megahash, false) == 0)
				{
					mysql_format(DB, global_str, sizeof global_str, "SELECT * FROM users WHERE Name = '%e'  LIMIT 1", PlayerName(playerid));
					mysql_tquery(DB, global_str, "PlayerIngreso", "i", playerid);
					SendClientMessage(playerid, -1, "Bienvenido de nuevo, te echabamos de menos.");
					
					/* Discord: discord.inc */
					format(gbl_log, sizeof(gbl_log), "(( `%s` se ha conectado y spawneado en el Servidor.))",  PlayerName(playerid));
					ConvertDiscordText(gbl_log);
					SendJoinEmbedMessage(DCHANNEL_LOG, gbl_log);
				}
				else
				{
					ShowPlayerDialog(playerid, dLogin, DIALOG_STYLE_PASSWORD, mHeader, mError,  ""COL_WHITE"Entrar", ""COL_WHITE"Salir");
				}
			}
			else Kick(playerid);
		}
        case dRegistro:{
            if(!response) return Kick(playerid);
            {
				SHA256_PassHash(inputtext, "123h1h23hh", PlayerData[playerid][TempHash], 64);
                ShowPlayerDialog(playerid, dGender, DIALOG_STYLE_MSGBOX, mHeader, ""COL_WHITE"A Continuacion indicanos tu genero.\nDependiendo de tu eleccion, se te sera seteada una skin default.", "Masculino", "Femenino");
            }
        }
		case dGender:
		{
		    if(response)
			{
				PlayerData[playerid][jSexo] = 1;
				PlayerData[playerid][jRopa] = 46;
			}
		    else if(!response)
		    {
				PlayerData[playerid][jSexo] = 2;
				PlayerData[playerid][jRopa] = 12;
			}
			new strAge[120+1];
			format(strAge, sizeof(strAge), ""COL_WHITE"Muy bien %s!\nAhora cuentanos. ¿Que edad tienes?", PlayerTemp(playerid), strAge);
			ShowPlayerDialog(playerid, dEdad, DIALOG_STYLE_INPUT, mHeader, strAge, ">>", "");
		}
		case dEdad:
		{
			if(!response) return Kick(playerid);
			format(global_str, sizeof(global_str), ""COL_SERVER"%s"COL_WHITE"; Solo puedes ingresar "COL_YELLOW"valores numericos"COL_WHITE".\nLa edad minima es de "COL_YELLOW"<13> "COL_WHITE"y la maxima de "COL_YELLOW"<50>"COL_WHITE".\n\nPor favor ingresa una "COL_YELLOW"Edad Valida"COL_WHITE".\n¿Qué edad tienes? Cuentanos.", PlayerTemp(playerid), global_str);
		    if(!IsNumeric(inputtext)) return ShowPlayerDialog(playerid, dEdad, DIALOG_STYLE_INPUT, ""COL_WHITE"A Continuación dinos tu edad.\t", global_str, "Aceptar", "Cancelar");
			if(strval(inputtext) < 13) return ShowPlayerDialog(playerid, dEdad, DIALOG_STYLE_INPUT, ""COL_WHITE"A Continuación dinos tu edad.\t", global_str, "Aceptar", "Cancelar");
			if(VarAge < 13 || VarAge > 50) return ShowPlayerDialog(playerid, dEdad, DIALOG_STYLE_INPUT, ""COL_WHITE"A Continuación dinos tu edad.\t", global_str, "Aceptar", "Cancelar");

			PlayerData[playerid][jEdad] = VarAge;
			format(global_str, sizeof(global_str), ""COL_WHITE"Excelente "COL_SERVER"%s"COL_WHITE"; Ya nos haz indicado tu Edad.\nAhora dinos, a que lugar de San Andreas pertenece\ntu personaje.", PlayerTemp(playerid));
			ShowPlayerDialog(playerid, dCountry, DIALOG_STYLE_MSGBOX, mHeader, global_str, ">>", "");
			
		}
		case dCountry:
		{
			if(!response) return Kick(playerid);
			format(global_str, sizeof(global_str), "Los Santos\nBlueBerry\nMontgomery\nPalomino Creek\nLas Venturas\nFort Cartson\nBayside\nSan Fierro\nAngel Pine", global_str);
			ShowPlayerDialog(playerid, dSelCountry, DIALOG_STYLE_LIST, "Elige una ciudad.", global_str, ">>", "");
		}
        case dSelCountry: 
        {
			if(!response) return Kick(playerid);
			format(PlayerData[playerid][jCountry], 64, "%s", txtCountry[listitem]);
			ShowPlayerDialog(playerid, dFinish, DIALOG_STYLE_MSGBOX, mHeader, ""COL_GREEN"Felicidades; Has culminado tu Registro; "COL_WHITE"Recuerda cumplir las\nnormas o podrias ser sancionado.", "Aceptar", "");
        }
		case dFinish:
		{
			if(response)
			{
				mysql_format(DB, global_str, sizeof global_str, "INSERT INTO users (Name, Password, Ropa, Sexo, Edad, Country) VALUES ('%e', '%e', '%i', '%i', '%i', '%e')",
				PlayerName(playerid),
				PlayerData[playerid][TempHash],
				PlayerData[playerid][jRopa],
				PlayerData[playerid][jSexo],
				PlayerData[playerid][jEdad],
				PlayerData[playerid][jCountry]);

				PlayerData[playerid][jScore] = 5;
				PlayerData[playerid][jHealth] = 100;
				PlayerData[playerid][jArmour] = 0;
				mysql_tquery(DB, global_str, "LoadAccountID", "i", playerid);

				FinishedIntro(playerid);
				printf("- %s Se ha registrado por Primera vez en el Servidor.", PlayerName(playerid));
			}
			else
			{
				SendClientMessage(playerid, HCOL_SERVER, "Cancelaste el Dialogo que tenias abierto, por lo tanto se te ha expulsado del Servidor.");
				Kick(playerid);
			}
		}
	}
	/* ############### DON TOUCH ############### */
	#if defined pregister_OnDialogResponse
		return pregister_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif

#define OnDialogResponse pregister_OnDialogResponse
#if defined pregister_OnDialogResponse
	forward pregister_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    /*new bool:cancel = (clickedid == Text:INVALID_TEXT_DRAW);

    if(IsPlayerConnected(playerid))
    {
		if(cancel)
		{
			Kick(playerid);
			return #IgnoredThis#(playerid);
		}
		else if(clickedid == #IgnoredThis#)
		{
			
		}
    }*/
	/* ############### DON TOUCH ############### */
	#if defined pregister_OnPlayerClickTextDraw
		return pregister_OnPlayerClickTextDraw(playerid, Text:clickedid);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerClickTextDraw
	#undef OnPlayerClickTextDraw
#else
	#define _ALS_OnPlayerClickTextDraw
#endif

#define OnPlayerClickTextDraw pregister_OnPlayerClickTextDraw
#if defined pregister_OnPlayerClickTextDraw
	forward pregister_OnPlayerClickTextDraw(playerid, Text:clickedid);
#endif

