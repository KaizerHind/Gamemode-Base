/*
# INFO: OnGameModeInit
# Server and Database Configuration. (ini file)

# INFO: OnGameModeExit
# Saving of all global data.

# INFO: OnPlayerConnect
# It is verified if the player uses "_" in the name and then we call the DB if everything is correct.


# INFO: OnPlayerDataCheck
# We check if the player is already registered or not.
*/
public OnGameModeInit()
{
	/* ======== [ Configuración general ] ======== */
	ShowPlayerMarkers(PLAYER_MARKERS_MODE_GLOBAL);
	ShowNameTags(true);
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
        SendOnLineEmbedMessage(DCHANNEL_LOG, "Connection to **Database** and **Discord** has been Successful - [MySQL]");
        print("The Connection with the DB has been Successful - [MySQL]\n");
    } else {
        print("The Connection with the DB has failed - [MySQL]");
        SendRconCommand("exit");
    }
	/* ################################ */
	/* ## From here you can add code ## */
	/* ################################ */
	SetTimer("PlayerIsDying", 5000, true);

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
	if(GetPVarInt(playerid,"Logged") == 1) return SpawnPlayer(playerid);
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
	SetPlayerColor(playerid, HCOL_TMPGRAY);
	CleanVars(playerid);
	if(playerid >= MAX_PLAYERS)
	{
	    SendClientMessage(playerid, HCOL_WHITE, "Currently only "COL_WHITE" 50 "COL_WHITE" users are allowed.\nIf you want to log in and can't, please report this on Discord.");
		Kick(playerid);
		return 1;
	}

	new last_name[24], NamePosition;

	GetPlayerName(playerid, last_name, 24);
	NamePosition = strfind(last_name, "_");
	
	if(!NamePosition || NamePosition < 1 || NamePosition > (strlen(last_name)-2) || InvalidCharacterName(last_name))
	{//
		strcat(st_InvalidName, ""COL_WHITE"Apparently you have entered the server with an invalid name.\n", sizeof(st_InvalidName));
		strcat(st_InvalidName, ""COL_WHITE"In "COL_SERVER""SERVER_PROJECT""COL_WHITE" names like the one you have are not allowed, since they\n", sizeof(st_InvalidName));
		strcat(st_InvalidName, ""COL_WHITE"the Server lacks a "COL_SERVER" Middle Role "COL_WHITE", therefore you must modify your name.\n", sizeof(st_InvalidName));
		strcat(st_InvalidName, ""COL_WHITE"\nThe correct use is "COL_SERVER"FirstName_Surname"COL_WHITE"; We recommend you to reboot once\nyou have changed your name.\n", sizeof(st_InvalidName));
		Dialog_Show(playerid, 9999, DIALOG_STYLE_MSGBOX, ""COL_SERVER""SERVER_NAME" "COL_WHITE"- Oops! It seems there is an error.", st_InvalidName, "Enter", "");

		/* Discord: discord.inc */
		format(DiscordLog, sizeof(DiscordLog), "(( `%s` you have been automatically kicked out by the server.\n\n**Reason:** `Wrong name`. ))", PlayerTemp(playerid));
		ConvertDiscordText(DiscordLog),
		SendGetOutEmbedMessage(DCHANNEL_LOG, DiscordLog);

		SetTimerEx("ReasonKick", 1000, false, "i", playerid);
		SetTimerEx("DialogKick", 2000, false, "i", playerid);
		return 1;
	}

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
	if(playerid == INVALID_PLAYER_ID) return 0;
	switch(reason)
	{
		case 0:
		{
			format(st_Disconnect, sizeof(st_Disconnect), "(( %s(%d) disconnected due to crash or timed-out. ))", PlayerTemp(playerid), playerid);
			format(DiscordLog, sizeof(DiscordLog), "(( `%s(%d)` disconnected due to crash or timed-out. ))", PlayerTemp(playerid), playerid);
		}
		case 1:
		{
			format(st_Disconnect, sizeof(st_Disconnect), "(( %s(%d) voluntarily disconnected. ))", PlayerName(playerid), playerid);
			format(DiscordLog, sizeof(DiscordLog), "(( `%s(%d)` voluntarily disconnected. ))", PlayerName(playerid), playerid);
		}
		case 2:
		{
			format(st_Disconnect, sizeof(st_Disconnect), "(( %s(%d) went offline. `(He was kicked or banned)` ))", PlayerTemp(playerid), playerid);
			format(DiscordLog, sizeof(DiscordLog), "(( `%s(%d)` went offline. `(He was kicked or banned)` ))", PlayerTemp(playerid), playerid);
		}
	}
	ProxDetector(20.0, playerid, st_Disconnect, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE);
	
	/* Discord: discord.inc */
	ConvertDiscordText(DiscordLog),
	SendGetOutEmbedMessage(DCHANNEL_LOG, DiscordLog);

	SavePlayer(playerid);
	/* ############### DON TOUCH ############### */
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
	if (GetPVarInt(playerid, "Logged"))
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

		format(global_str, sizeof(global_str),""COL_WHITE"¡Welcome back "COL_SERVER"%s"COL_WHITE"; Your last connection was:\n"COL_SERVER"%s.\n"COL_WHITE"\n\nEnter your password to enter the Server.\n\nIf you are not the owner of said account, we\ninvite you to relog with another name that is available.",
		PlayerName_(playerid),
		ReturnDate());

		Dialog_Show(playerid, dLogin, DIALOG_STYLE_PASSWORD, mHeader, global_str, ""COL_WHITE"Enter", ""COL_WHITE"Salir");
		}else{

		ClearChat(playerid, 100);
		StartLoginCamera(playerid);
		/* Discord: discord.inc */
		format(DiscordLog, sizeof(DiscordLog), "(( `%s` has entered the Server and will begin to take the Role Exam. **[Part 1/2]** ))",  PlayerTemp(playerid));
		ConvertDiscordText(DiscordLog);
		SendJoinEmbedMessage(DCHANNEL_LOG, DiscordLog);
		
		format(global_str, sizeof(global_str), ""COL_WHITE"Welcome to "COL_SERVER""SERVER_PROJECT" "COL_SERVER"%s"COL_WHITE"! We hope you have fun within the Community, don't forget to respect the Rules\nand play in a healthy way, any foul can lead to a sanction.\n\nWithout anything else to say; Let's proceed to take your data.\n\nEnter a password to register your account.", PlayerName(playerid));
		Dialog_Show(playerid, dRegistro, DIALOG_STYLE_PASSWORD, mHeader, global_str, ""COL_WHITE"Enter", "");
	}
	return 1;
}

Dialog:dLogin(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new megahash[64 + 1];
		SHA256_PassHash(inputtext, "123h1h23hh", megahash, 64);
		if(strcmp(PlayerData[playerid][jPass], megahash, false) == 0)
		{
			mysql_format(DB, global_str, sizeof global_str, "SELECT * FROM users WHERE Name = '%e'  LIMIT 1", PlayerName(playerid));
			mysql_tquery(DB, global_str, "PlayerIngreso", "i", playerid);
			SendClientMessage(playerid, -1, "Bienvenido de vuelta, si tienes duda alguna duda, recuerda usa "COL_SERVER"/ayuda"COL_WHITE" o "COL_SERVER"/duda"COL_WHITE".");
			
			/* Discord: discord.inc */
			format(DiscordLog, sizeof(DiscordLog), "(( `%s` se ha conectado y spawneado en el Servidor.\nSu ultima conexion fue el: `%s` ))",  
			PlayerName_(playerid),
			ReturnDate());

			ConvertDiscordText(DiscordLog);
			SendJoinEmbedMessage(DCHANNEL_LOG, DiscordLog);
		}
		else
		{
			Dialog_Show(playerid, dLogin, DIALOG_STYLE_PASSWORD, mHeader, mError,  ""COL_WHITE"Entrar", ""COL_WHITE"Salir");
		}
	}
}

Dialog:dRegistro(playerid, response, listitem, inputtext[])
{
	if(response)
	SHA256_PassHash(inputtext, "123h1h23hh", PlayerData[playerid][TempHash], 64);
	Dialog_Show(playerid, dGender, DIALOG_STYLE_MSGBOX, mHeader, ""COL_WHITE"Next, tell us your gender.\Depending on your choice, a default skin will be set for you.", "Male", "Female");
	return 1;
}

Dialog:dGender(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		PlayerData[playerid][jGender] = 1;
		PlayerData[playerid][jSkin] = 46;
	}
	else if(!response)
	{
		PlayerData[playerid][jGender] = 2;
		PlayerData[playerid][jSkin] = 12;
	}
	new strAge[120+1];
	format(strAge, sizeof(strAge), ""COL_WHITE"Very good %s!\nNow tell us. How old are you?", PlayerTemp(playerid), strAge);
	Dialog_Show(playerid, dEdad, DIALOG_STYLE_INPUT, mHeader, strAge, ">>", "");
	return 1;
}

Dialog:dEdad(playerid, response, listitem, inputtext[])
{
	new VarAge = strval(inputtext);
	if(!response) return 1;
	format(global_str, sizeof(global_str), ""COL_SERVER"%s"COL_WHITE"; You can only enter "COL_YELLOW" numerical values "COL_WHITE".\nThe minimum age is "COL_YELLOW" <13> "COL_WHITE" and the maximum is "COL_YELLOW" <50> "COL_WHITE".\n\nPlease enter a "COL_YELLOW"Valid Age"COL_WHITE".\nHow old are you? Tell us.", PlayerTemp(playerid), global_str);
	if(!IsNumeric(inputtext)) return Dialog_Show(playerid, dEdad, DIALOG_STYLE_INPUT, ""COL_WHITE"Please tell us your age.\t", global_str, "Enter", "Cancel");
	if(strval(inputtext) < 13) return Dialog_Show(playerid, dEdad, DIALOG_STYLE_INPUT, ""COL_WHITE"Please tell us your age.\t", global_str, "Enter", "Cancel");
	if(VarAge < 13 || VarAge > 50) return Dialog_Show(playerid, dEdad, DIALOG_STYLE_INPUT, ""COL_WHITE"Please tell us your age.\t", global_str, "Enter", "Cancel");

	PlayerData[playerid][jAge] = VarAge;
	format(global_str, sizeof(global_str), ""COL_WHITE"Excellent "COL_SERVER"%s"COL_WHITE"; You have already told us your Age.\nNow tell us, where in San Andreas\nyour character belongs.", PlayerTemp(playerid));
	Dialog_Show(playerid, dCountry, DIALOG_STYLE_MSGBOX, mHeader, global_str, ">>", "");
	return 1;
}

Dialog:dCountry(playerid, response, listitem, inputtext[])
{
	if(!response) return 1;
	format(global_str2, sizeof(global_str2), "Los Santos\nBlueBerry\nMontgomery\nPalomino Creek\nLas Venturas\nFort Cartson\nBayside\nSan Fierro\nAngel Pine");
	Dialog_Show(playerid, dSelCountry, DIALOG_STYLE_LIST, "Select a Country", global_str2, ">>", "");
	return 1;
}

Dialog:dSelCountry(playerid, response, listitem, inputtext[])
{
	if(!response) return 1;
	format(PlayerData[playerid][jCountry], 64, "%s", txtCountry[listitem]);
	Dialog_Show(playerid, dFinish, DIALOG_STYLE_MSGBOX, mHeader, ""COL_GREEN"Congratulations; You have completed your Registration; "COL_WHITE"Remember to follow the\nrules or you could be penalized.", "Enter", "");
	return 1;
}

Dialog:dFinish(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		mysql_format(DB, global_str, sizeof global_str, "INSERT INTO users (Name, Password, Skin, Gender, Age, Country, Account_Register, Acc_Last_Session) VALUES ('%e', '%e', '%i', '%i', '%i', '%e', '%s', '%s')",
		PlayerName(playerid),
		PlayerData[playerid][TempHash],
		PlayerData[playerid][jSkin],
		PlayerData[playerid][jGender],
		PlayerData[playerid][jAge],
		PlayerData[playerid][jCountry],
		ReturnDate(), ReturnDate()
		);

		PlayerData[playerid][jScore] = 5;
		PlayerData[playerid][jHealth] = 100;
		PlayerData[playerid][jArmour] = 0;

		mysql_tquery(DB, global_str, "LoadAccountID", "i", playerid);

		FinishedIntro(playerid);
		printf("- %s You have registered for the first time on the server.", PlayerName(playerid));
	}
	else
	{
		SendClientMessage(playerid, HCOL_SERVER, "You canceled the Dialog that you had open, therefore you have been expelled from the Server.");
		Kick(playerid);
	}
	return 1;
}

