/*
# INFORMACION: OnPlayerSpawn
#
# if(PlayerData[playerid][jHasDied] == 0) | Verificamos que el jugador esta vivo y ha spawneado correctamente.
# if(PlayerData[playerid][jHasDied] == 1) | Verificamos que el jugador esta herido y lo spawneamos en la misma posicion, enviando un aviso de que esta herido.
# if(PlayerData[playerid][jHasDied] == 2) | Verificamos que el jugador ha muerto y es enviado al hospital. (./content/server/utils (IsPlayerDying))


# INFORMACION: OnPlayerDeath
#
# if(PlayerData[playerid][jHasDied] == 0) | Verificamos que el jugador esta vivo y ha spawneado correctamente.
# if(PlayerData[playerid][jHasDied] == 2) | Verificamos que el jugador ha muerto y es enviado al hospital. (./content/server/utils (IsPlayerDying))


# INFORMACION: OnPlayerText
# Nada en especial, todo lo relacionado a texto. (Sistema de acentos y chat normal)

# INFORMACION: OnPlayerCommandPerformed
# Si el usuario digita un comando erroneo, saltara un Textdraw + un sonido.

*/

public OnPlayerSpawn(playerid)
{
	if (GetPVarInt(playerid, "Logueado"))
	{
		if(PlayerData[playerid][jHasDied] == 0)
		{
			PlayerFreeze(playerid, 3);

			SetPlayerHealth(playerid, PlayerData[playerid][jHealth]);
			SetPlayerArmour(playerid, PlayerData[playerid][jArmour]);
			SetPlayerScore(playerid, PlayerData[playerid][jScore]);

			ac_SetPlayerPos(playerid, PlayerData[playerid][jPosX], PlayerData[playerid][jPosY], PlayerData[playerid][jPosZ]);
			ac_GetPlayerFacingAngle(playerid, PlayerData[playerid][jPosA]);
			
			return 1;
		}
		else if(PlayerData[playerid][jHasDied] == 1)
		{
			SetPlayerSkin(playerid, PlayerData[playerid][jSkin]);
			SetPlayerHealth(playerid, 90);
			SetPlayerInterior(playerid, 0);
			
			ac_SetPlayerPos(playerid, PlayerData[playerid][jPosX], PlayerData[playerid][jPosY], PlayerData[playerid][jPosZ]);
			ac_GetPlayerFacingAngle(playerid, PlayerData[playerid][jPosA]);
			SendClientMessage(playerid, HCOL_RED, "* Estas gravemente herido y comienzas a perder sangre..\n"COL_WHITE"");
			SendClientMessage(playerid, HCOL_DO, "[Anonimo]: * Una persona ha visto la situacion y ha llamado al 911. *");

			ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, true, false, false, true, 3000, true);
		}
		else if(PlayerData[playerid][jHasDied] == 2)
		{			
			SetPlayerHealth(playerid, 30);
			ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, false, false, false, false, 3000, true);
			SendClientMessage(playerid, -1, "Medico: Hey, al parecer ya has despertado, tuviste una fuerte contusion.");
		}
	}
	/* ############**DON TOUCH ############***/
	#if defined player_OnPlayerSpawn
		return player_OnPlayerSpawn(playerid);
	#else
		return 1;
	#endif
}

public OnPlayerDeath(playerid, killerid, reason)
{
	if(PlayerData[playerid][jHasDied] == 0)
	{
		GetPlayerPos(playerid, PlayerData[playerid][jPosX], PlayerData[playerid][jPosY], PlayerData[playerid][jPosZ]);
		acc_SetSpawnInfo(playerid, 0, PlayerData[playerid][jSkin], PlayerData[playerid][jPosX], PlayerData[playerid][jPosY], PlayerData[playerid][jPosZ], PlayerData[playerid][jPosA], 0,0,0,0,0,0);
		PlayerData[playerid][jHasDied] = 1;
		return 1;
	}
	else if(PlayerData[playerid][jHasDied] == 1)
	{
		acc_SetSpawnInfo(playerid, 0, PlayerData[playerid][jSkin], 1188.0311, -1321.3394, 13.3687, 0.0, 0, 0, 0, 0, 0, 0);
		PlayerData[playerid][jHasDied] = 2;
	}
    /* ############**DON TOUCH ############***/
    #if defined player_OnPlayerDeath
        return player_OnPlayerDeath(playerid, killerid, reason);
    #else
        return 1;
    #endif
}

public OnPlayerText(playerid, text[])	
{
    if(GetPVarInt(playerid,"Logueado") == 0) return SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: "COL_WHITE"Debes haber hecho spawn para enviar mensajes.");
	if(PlayerMuted[playerid] == 1){SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: "COL_WHITE" Estas muteado, no puedes enviar mensajes."); return 0;}

 	switch(PlayerData[playerid][jAccent])
	{
		case 0, 1:
		{
			format(global_str2, sizeof(global_str2), "%s dice: %s", PlayerName(playerid), text);
            ProxDetector(20.0, playerid, global_str2, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE);
			SetPlayerChatBubble(playerid, text, HCOL_WHITE, 20.0, 5000);

			/* Discord: discord.inc */
			format(DiscordLog, sizeof(DiscordLog), "**%s(%d) dice:**\n```fix\n\
			%s```", PlayerName(playerid), playerid, text);

			ConvertDiscordText(DiscordLog),
			SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
		}
		case 2:{
			format(global_str2, sizeof(global_str2), "[Acento Colombiano] %s dice: %s", PlayerName(playerid), text);
			ProxDetector(20.0, playerid, global_str2,HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE);
			SetPlayerChatBubble(playerid,text, HCOL_WHITE,20.0,5000);

			/* Discord: discord.inc */
			format(DiscordLog, sizeof(DiscordLog), "**%s(%d) dice:**\n```fix\n\
			%s```", PlayerName(playerid), playerid, text);

			ConvertDiscordText(DiscordLog),
			SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
		}
		case 3:{
			format(global_str2, sizeof(global_str2), "[Acento Cubano] %s dice: %s", PlayerName(playerid), text);
			ProxDetector(20.0, playerid, global_str2,HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE);
			SetPlayerChatBubble(playerid,text, HCOL_WHITE,20.0,5000);
			
			/* Discord: discord.inc */
			format(DiscordLog, sizeof(DiscordLog), "**%s(%d) dice:**\n```fix\n\
			%s```", PlayerName(playerid), playerid, text);

			ConvertDiscordText(DiscordLog),
			SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
		}
		case 4:{
			format(global_str2, sizeof(global_str2), "[Acento Dominicano] %s dice: %s", PlayerName(playerid), text);
			ProxDetector(20.0, playerid, global_str2,HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE);
			SetPlayerChatBubble(playerid,text, HCOL_WHITE,20.0,5000);
			
			/* Discord: discord.inc */
			format(DiscordLog, sizeof(DiscordLog), "**%s(%d) dice:**\n```fix\n\
			%s```", PlayerName(playerid), playerid, text);

			ConvertDiscordText(DiscordLog),
			SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
		}
		case 5:{
			format(global_str2, sizeof(global_str2), "[Acento Venezolano] %s dice: %s", PlayerName(playerid), text);
			ProxDetector(20.0, playerid, global_str2,HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE);
			SetPlayerChatBubble(playerid,text, HCOL_WHITE,20.0,5000);
			
			/* Discord: discord.inc */
			format(DiscordLog, sizeof(DiscordLog), "**%s(%d) dice:**\n```fix\n\
			%s```", PlayerName(playerid), playerid, text);

			ConvertDiscordText(DiscordLog),
			SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
		}
		case 6:{
			format(global_str2, sizeof(global_str2), "[Acento Argentino] %s dice: %s", PlayerName(playerid), text);
			ProxDetector(20.0, playerid, global_str2,HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE);
			SetPlayerChatBubble(playerid,text, HCOL_WHITE,20.0,5000);
			
			/* Discord: discord.inc */
			format(DiscordLog, sizeof(DiscordLog), "**%s(%d) dice:**\n```fix\n\
			%s```", PlayerName(playerid), playerid, text);

			ConvertDiscordText(DiscordLog),
			SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
		}
		case 7:{
			format(global_str2, sizeof(global_str2), "[Acento Uruguayo] %s dice: %s", PlayerName(playerid), text);
			ProxDetector(20.0, playerid, global_str2,HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE);
			SetPlayerChatBubble(playerid,text, HCOL_WHITE,20.0,5000);
			
			/* Discord: discord.inc */
			format(DiscordLog, sizeof(DiscordLog), "**%s(%d) dice:**\n```fix\n\
			%s```", PlayerName(playerid), playerid, text);

			ConvertDiscordText(DiscordLog),
			SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
		}
        case 8:{
			format(global_str2, sizeof(global_str2), "[Acento Britanico] %s dice: %s", PlayerName(playerid), text);
			ProxDetector(20.0, playerid, global_str2,HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE);
			SetPlayerChatBubble(playerid,text, HCOL_WHITE,20.0,5000);
			
			/* Discord: discord.inc */
			format(DiscordLog, sizeof(DiscordLog), "**%s(%d) dice:**\n```fix\n\
			%s```", PlayerName(playerid), playerid, text);

			ConvertDiscordText(DiscordLog),
			SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
		}
		case 9:{
			format(global_str2, sizeof(global_str2), "[Acento Asiático] %s dice: %s", PlayerName(playerid), text);
			ProxDetector(20.0, playerid, global_str2,HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE);
			SetPlayerChatBubble(playerid,text, HCOL_WHITE,20.0,5000);
			
			/* Discord: discord.inc */
			format(DiscordLog, sizeof(DiscordLog), "**%s(%d) dice:**\n```fix\n\
			%s```", PlayerName(playerid), playerid, text);

			ConvertDiscordText(DiscordLog),
			SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
		}
		case 10:{
			format(global_str2, sizeof(global_str2), "[Acento Ruso] %s dice: %s", PlayerName(playerid), text);
			ProxDetector(20.0, playerid, global_str2,HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE);
			SetPlayerChatBubble(playerid,text, HCOL_WHITE,20.0,5000);
			
			/* Discord: discord.inc */
			format(DiscordLog, sizeof(DiscordLog), "**%s(%d) dice:**\n```fix\n\
			%s```", PlayerName(playerid), playerid, text);

			ConvertDiscordText(DiscordLog),
			SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
		}
		case 11:{
			format(global_str2, sizeof(global_str2), "[Acento Americano] %s dice: %s", PlayerName(playerid), text);
			ProxDetector(20.0, playerid, global_str2,HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE);
			SetPlayerChatBubble(playerid,text, HCOL_WHITE,20.0,5000);
			
			/* Discord: discord.inc */
			format(DiscordLog, sizeof(DiscordLog), "**%s(%d) dice:**\n```fix\n\
			%s```", PlayerName(playerid), playerid, text);

			ConvertDiscordText(DiscordLog),
			SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
		}
		case 12:{
			format(global_str2, sizeof(global_str2), "[Acento Francés] %s dice: %s", PlayerName(playerid), text);
			ProxDetector(20.0, playerid, global_str2,HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE);
			SetPlayerChatBubble(playerid,text, HCOL_WHITE,20.0,5000);
			
			/* Discord: discord.inc */
			format(DiscordLog, sizeof(DiscordLog), "**%s(%d) dice:**\n```fix\n\
			%s```", PlayerName(playerid), playerid, text);

			ConvertDiscordText(DiscordLog),
			SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
		}
		case 13:{
			format(global_str2, sizeof(global_str2), "[Acento Italiano] %s dice: %s", PlayerName(playerid), text);
			ProxDetector(20.0, playerid, global_str2,HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE);
			SetPlayerChatBubble(playerid,text, HCOL_WHITE,20.0,5000);
			
			/* Discord: discord.inc */
			format(DiscordLog, sizeof(DiscordLog), "**%s(%d) dice:**\n```fix\n\
			%s```", PlayerName(playerid), playerid, text);

			ConvertDiscordText(DiscordLog),
			SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
		}
		case 14:{
			format(global_str2, sizeof(global_str2), "[Acento Hippie] %s dice: %s", PlayerName(playerid), text);
			ProxDetector(20.0, playerid, global_str2,HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE);
			SetPlayerChatBubble(playerid,text, HCOL_WHITE,20.0,5000);
			
			/* Discord: discord.inc */
			format(DiscordLog, sizeof(DiscordLog), "**%s(%d) dice:**\n```fix\n\
			%s```", PlayerName(playerid), playerid, text);

			ConvertDiscordText(DiscordLog),
			SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
		}
    }
    /* ############**DON TOUCH ############***/
    #if defined player_OnPlayerText
        return player_OnPlayerText(playerid, text[]);
    #else
        return 0;
    #endif
}

public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags)
{
	if (result == -1)
	{
		SetTimerEx("s_err_command", 0, false, "d", playerid);
		SetTimerEx("h_err_command", 4000, false, "d", playerid);
		return 0;
	}
    /* ############**DON TOUCH ############***/
    #if defined player_OnPlayerCommandPerformed
        return player_OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags);
    #else
        return 1;
    #endif
}

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    new bool:cancel = (clickedid == Text:INVALID_TEXT_DRAW);

    if(IsPlayerConnected(playerid))
    {
		if(cancel)
		{
			return SendClientMessage(playerid, HCOL_WHITE, "Has cancelado el Textdraw.");
		}
		/*else if(clickedid == Variable){}*/
    }
	/* ############**DON TOUCH ############***/
	#if defined pregister_OnPlayerClickTextDraw
		return pregister_OnPlayerClickTextDraw(playerid, Text:clickedid);
	#else
		return 1;
	#endif
}

/* # ALS FORMATS | NO TOUCH # */

#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn player_OnPlayerSpawn
#if defined player_OnPlayerSpawn
	forward player_OnPlayerSpawn(playerid);
#endif
////////////////////////////////////////////
#if defined _ALS_OnPlayerDeath
    #undef OnPlayerDeath
#else
    #define _ALS_OnPlayerDeath
#endif

#define OnPlayerDeath player_OnPlayerDeath
#if defined player_OnPlayerDeath
    forward player_OnPlayerDeath(playerid, killerid, reason);
#endif
////////////////////////////////////////////
#if defined _ALS_OnPlayerText
    #undef OnPlayerText
#else
    #define _ALS_OnPlayerText
#endif

#define OnPlayerText player_OnPlayerText
#if defined player_OnPlayerText
    forward player_OnPlayerText(playerid, text[]);
#endif
////////////////////////////////////////////
#if defined _ALS_OnPlayerCommandPerformed
    #undef OnPlayerCommandPerformed
#else
    #define _ALS_OnPlayerCommandPerformed
#endif

#define OnPlayerCommandPerformed player_OnPlayerCommandPerformed
#if defined player_OnPlayerCommandPerformed
    forward player_OnPlayerCommandPerformed(playerid, cmdtext[], success);
#endif
////////////////////////////////////////////
#if defined _ALS_OnPlayerClickTextDraw
	#undef OnPlayerClickTextDraw
#else
	#define _ALS_OnPlayerClickTextDraw
#endif

#define OnPlayerClickTextDraw pregister_OnPlayerClickTextDraw
#if defined pregister_OnPlayerClickTextDraw
	forward pregister_OnPlayerClickTextDraw(playerid, Text:clickedid);
#endif