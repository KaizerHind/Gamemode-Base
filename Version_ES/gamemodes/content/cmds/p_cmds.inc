/*
# General Commands #
*/

cmd:dicc(playerid){ Dialog_Show(playerid, 9990, DIALOG_STYLE_MSGBOX, mHeader, "{7bbfcf}• Server Errors Diccionary\n\n{7bbfcf}[x] "COL_WHITE"Invalid Error "COL_E_CODE"[00] "COL_WHITE"/ El Usuario no a spawneado.\n{7bbfcf}[x] "COL_WHITE"Invalid Error "COL_E_CODE"[01] "COL_WHITE"/ Usuario Desconectado\n{7bbfcf}[x] "COL_WHITE"Invalid Error "COL_E_CODE"[02] "COL_WHITE"/ Flood/Temporizador de Mensajes(5/10 segs)\n{7bbfcf}[x] "COL_WHITE"Invalid Error "COL_E_CODE"[03] "COL_WHITE"/ Ningun usuario cerca\n{7bbfcf}[x] "COL_WHITE"Invalid Error "COL_E_CODE"[04] "COL_WHITE"/ Usuario en Vehiculo\n{7bbfcf}[x] "COL_WHITE"Invalid Error "COL_E_CODE"[05] "COL_WHITE"/ El Usuario no a muerto.", "Aceptar", ""); return 1;}

cmd:acento(playerid, params[]){
    new accentid;
    if(GetPVarInt(playerid,"Logueado") == 0) return SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: "COL_WHITE"Invalid Error "COL_E_CODE"[00]");
    if(AttemptAction[playerid] == 1) return SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: "COL_WHITE"Invalid Error "COL_E_CODE"[02] ");

    if(sscanf(params, "d", accentid)){
        SendClientMessage(playerid, -1, ""COL_SERVER">> "COL_WHITE"/acento [1-14]");
        SendClientMessage(playerid, HCOL_WHITE, "Acentos I:   [1]Normal, [2]Colombiano, [3]Cubano, [4]Dominicano, [5]Venezolano, [6]Argentino.");
        SendClientMessage(playerid, HCOL_WHITE, "Acentos II:  [7]Uruguayo, [8]Britanico, [9]Asiatico, [10]Ruso, [11]Americano, [12]Frances.");
        SendClientMessage(playerid, HCOL_WHITE, "Acentos III: [13]Italiano, [14]Hippie.");
        return 1;
    }

    AttemptAction[playerid] = 1;
    SetTimerEx("WaitingAttemp", 5000, false, "i", playerid);
    
    if(accentid < 1 || accentid > 14) return SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: "COL_WHITE"ID Invalida; Actualmente solo hay disponibles "COL_RED"14"COL_WHITE" Acentos.");
    switch(accentid){
        case 1:{
            PlayerData[playerid][jAccent] = 1;
            SendClientMessage(playerid, HCOL_WHITE, "Has modificado tu acento a uno comun; Si deseas cambiarlo usa /acento.");
        }
		case 2:{
            PlayerData[playerid][jAccent] = 2;
            SendClientMessage(playerid, HCOL_WHITE, "Has modificado tu acento a Colombiano; Si deseas cambiarlo usa /acento.");
		}
		case 3:{
            PlayerData[playerid][jAccent] = 3;
            SendClientMessage(playerid, HCOL_WHITE, "Has modificado tu acento a Cubano; Si deseas cambiarlo usa /acento.");
		}
		case 4:{
            PlayerData[playerid][jAccent] = 4;
            SendClientMessage(playerid, HCOL_WHITE, "Has modificado tu acento a Dominicano; Si deseas cambiarlo usa /acento.");
		}
		case 5:{
            PlayerData[playerid][jAccent] = 5;
            SendClientMessage(playerid, HCOL_WHITE, "Has modificado tu acento a Venezolano; Si deseas cambiarlo usa /acento.");
		}
		case 6:{
            PlayerData[playerid][jAccent] = 6;
            SendClientMessage(playerid, HCOL_WHITE, "Has modificado tu acento a Argentino; Si deseas cambiarlo usa /acento.");
		}
		case 7:{
            PlayerData[playerid][jAccent] = 7;
            SendClientMessage(playerid, HCOL_WHITE, "Has modificado tu acento a Uruguayo; Si deseas cambiarlo usa /acento.");
		}
        case 8:{
            PlayerData[playerid][jAccent] = 8;
            SendClientMessage(playerid, HCOL_WHITE, "Has modificado tu acento a Britanico; Si deseas cambiarlo usa /acento.");
		}
		case 9:{
            PlayerData[playerid][jAccent] = 9;
            SendClientMessage(playerid, HCOL_WHITE, "Has modificado tu acento a Asiatico; Si deseas cambiarlo usa /acento.");
		}
		case 10:{
            PlayerData[playerid][jAccent] = 10;
            SendClientMessage(playerid, HCOL_WHITE, "Has modificado tu acento a Ruso; Si deseas cambiarlo usa /acento.");
		}
		case 11:{
            PlayerData[playerid][jAccent] = 11;
            SendClientMessage(playerid, HCOL_WHITE, "Has modificado tu acento a Americano; Si deseas cambiarlo usa /acento.");
		}
		case 12:{
            PlayerData[playerid][jAccent] = 12;
            SendClientMessage(playerid, HCOL_WHITE, "Has modificado tu acento a Frances; Si deseas cambiarlo usa /acento.");
		}
		case 13:{
            PlayerData[playerid][jAccent] = 13;
            SendClientMessage(playerid, HCOL_WHITE, "Has modificado tu acento a Italiano; Si deseas cambiarlo usa /acento.");
		}
		case 14:{
            PlayerData[playerid][jAccent] = 14;
            SendClientMessage(playerid, HCOL_WHITE, "Has modificado tu acento a Hippie; Si deseas cambiarlo usa /acento.");
		}
    }
    return 1;
}alias:acento("ac")

cmd:me(playerid, params[]){
    if(GetPVarInt(playerid,"Logueado") == 0) return SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: "COL_WHITE"Invalid Error "COL_E_CODE"[00]");
    if(isnull(params)) return SendClientMessage(playerid, HCOL_WHITE, ""COL_SERVER">> "COL_WHITE"/me (acción)");
   
    format(global_str2, sizeof(global_str2), "%s %s.", PlayerName(playerid), params);
    ProxDetector(20.0, playerid, global_str2, HCOL_ME, HCOL_ME, HCOL_ME, HCOL_ME, HCOL_ME);
    return 1;
}

cmd:do(playerid, params[]){
    if(GetPVarInt(playerid,"Logueado") == 0) return SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: "COL_WHITE"Invalid Error "COL_E_CODE"[00]");
    if(!isnull(params)){
        format(global_str2, sizeof(global_str2), "* %s %s.", PlayerName(playerid), params);
        return ProxDetector(20.0, playerid, global_str2, HCOL_DO, HCOL_DO, HCOL_DO, HCOL_DO, HCOL_DO);
    }
    else SendClientMessage(playerid, -1, ""COL_SERVER">> "COL_WHITE"/do <Acción>");
    return 1;
}

cmd:b(playerid, params[]){
    if(GetPVarInt(playerid,"Logueado") == 0) return SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: "COL_WHITE"Invalid Error "COL_E_CODE"[00]");
    if(isnull(params)) return SendClientMessage(playerid, HCOL_WHITE, ""COL_SERVER">> "COL_WHITE"/b (chat ooc)");
    if(AttemptAction[playerid] == 1) return SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: "COL_WHITE"Invalid Error "COL_E_CODE"[02] ");

    AttemptAction[playerid] = 1;
    SetTimerEx("WaitingAttemp", 5000, false, "i", playerid);

    format(global_str2, sizeof(global_str2), "(([OOC] %s(%d): %s))", PlayerName(playerid), playerid, params);    
    ProxDetector(10.0, playerid, global_str2, HCOL_TMPGRAY, HCOL_TMPGRAY, HCOL_TMPGRAY, HCOL_TMPGRAY, HCOL_TMPGRAY);

    /* Discord: discord.inc */
    format(DiscordLog, sizeof(DiscordLog), "**(([OOC] %s(%d):))**\n```fix\n\
    %s```", PlayerName(playerid), playerid, global_str2);

    ConvertDiscordText(DiscordLog),
    SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
    return 1;
}

cmd:susurrar(playerid, params[]){
	new idx;
    if(GetPVarInt(playerid,"Logueado") == 0) return SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: "COL_WHITE"Invalid Error "COL_E_CODE"[00]");
 	if(IsPlayerConnected(playerid))
	{
		if(sscanf(params,"u",params[0])) return SendClientMessage(playerid, -1, ""COL_SERVER">> "COL_WHITE"/s id texto"),1;
		if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: Invalid Error "COL_E_CODE"[01]");
		if(params[0] == playerid) return SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: "COL_WHITE"No puedes enviarte susurros a ti mismo.");

		new length = strlen(params);
		while ((idx < length) && (params[idx] <= ' '))
		{
			idx++;
		}
		new offset = idx;
		new result[100];
		while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
		{
			result[idx - offset] = params[idx]; idx++;
		}
		result[idx - offset] = EOS;

		if(!strlen(result))
		{
			SendClientMessage(playerid, -1, ""COL_SERVER">> "COL_WHITE"/susurrar id texto");
			return 1;
		}
		if(!GetPlayerInRange(1.5, playerid, params[0]))
		{
			SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: "COL_WHITE"Invalid Error "COL_E_CODE"[03]");
			return 1;
		}
		format(global_str2, sizeof(global_str2), "%s susurra algo al oído de %s", PlayerName(params[0]), params[0], params[1]);
		ProxDetector(15.0, playerid, global_str2, HCOL_TMPGRAY, HCOL_TMPGRAY, HCOL_TMPGRAY, HCOL_TMPGRAY, HCOL_TMPGRAY);
		
        format(global_str2, sizeof(global_str2), "%s te susurra al oído: %s", PlayerName(playerid), playerid, params[1]);
		SendClientMessage(params[0],  HCOL_TMPGRAY, global_str2);
		
        format(global_str2, sizeof(global_str2), "Susurras al oído de %s: %s", PlayerName(params[0]), params[0], params[1]);
		SendClientMessage(playerid,  HCOL_TMPGRAY, global_str2);
	}
	return 1;
}alias:susurrar("s")

cmd:gritar(playerid, params[]){
    if(GetPVarInt(playerid,"Logueado") == 0) return SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: "COL_WHITE"Invalid Error "COL_E_CODE"[00]");
    if(!isnull(params)){
        format(global_str2, sizeof(global_str2), "%s grita: %s!", PlayerName(playerid), params);
        ProxDetector(30.0, playerid, global_str2,HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE);
        
        format(global_str2, sizeof(global_str2), "%s!", params);

        /* Discord: discord.inc */
        format(DiscordLog, sizeof(DiscordLog), "**%s(%d) grita:**\n```fix\n\
        %s```", PlayerName(playerid), playerid, global_str2);

        ConvertDiscordText(DiscordLog),
        SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
        return SetPlayerChatBubble(playerid,global_str2,HCOL_WHITE,60.0,5000);
    } else SendClientMessage(playerid, -1, ""COL_SERVER">> "COL_WHITE"/g texto");
    return 1;
}alias:gritar("g")

cmd:intentar(playerid, params[]){
    if(GetPVarInt(playerid,"Logueado") == 0) return SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: "COL_WHITE"Invalid Error "COL_E_CODE"[00]");
    if(AttemptAction[playerid] == 1) return SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: "COL_WHITE"Invalid Error "COL_E_CODE"[02]");
    new RandAttempt = random(2)+1;

    if(!sscanf(params, "s[128]", params[0]))
    {
        if(RandAttempt == 1)
        {
            format(global_str2, sizeof(global_str2), "* %s intenta %s y lo logra.", PlayerName(playerid), params[0]);
            ProxDetector(3.0, playerid, global_str2, HCOL_GREEN, HCOL_GREEN, HCOL_GREEN, HCOL_GREEN, HCOL_GREEN);
        }
        else
        {
            format(global_str2, sizeof(global_str2), "* %s intenta %s pero falla.", PlayerName(playerid), params[0]);
            ProxDetector(3.0, playerid, global_str2, HCOL_RED, HCOL_RED, HCOL_RED, HCOL_RED, HCOL_RED);
        }
        AttemptAction[playerid] = 1;
        SetTimerEx("WaitingAttemp", 10000, false, "i", playerid);
    } else SendClientMessage(playerid, -1, ""COL_SERVER">> "COL_WHITE"/intentar <Acción>");
    return 1;
}

/*
# Service General - Commands #
*/
cmd:curar(playerid){
    if(GetPVarInt(playerid,"Logueado") == 0) return SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: "COL_WHITE"Invalid Error "COL_E_CODE"[00]");
    
    new Float:health;
    GetPlayerHealth(playerid, health);
    if(GetPlayerMoney(playerid) < 750) return SendClientMessage(playerid, -1, "Enfemera: !Al parecer no tienes el dinero suficiente!");
    if(health < 45.0)
    {
        SendClientMessage(playerid, -1, "Medico: Al parecer no tienes enfermedades que curar, deberias ir a comer algo mejor.");
    }
    else
    {
        GivePlayerMoney(playerid, -750);
        SetPlayerHealth(playerid, 100);
        SendClientMessage(playerid, -1, "Medico: ¡Enhorabuena; Todas tus enfermedades han sido curadas!");
    }
    return 1;
}