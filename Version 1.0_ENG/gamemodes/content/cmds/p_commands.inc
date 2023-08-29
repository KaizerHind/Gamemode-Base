/*
# General Commands #
*/
CMD:accent(playerid, params[])
{
    new accentid;
    if(GetPVarInt(playerid,"Logueado") == 0) return SendClientMessage(playerid, -1, ""COL_ERROR"[Server]: "COL_WHITE"You arent logged in.");
    if(sscanf(params, "d", accentid)){
        SendClientMessage(playerid, -1, ""COL_SERVER">> "COL_WHITE"/accent [1-14]");
        SendClientMessage(playerid, HCOL_WHITE, "Accents I:   [1]Normal, [2]Colombian, [3]Cuban, [4]Dominican, [5]Venezuelan, [6]Argentinian.");
        SendClientMessage(playerid, HCOL_WHITE, "Accents II:  [7]Uruguayan, [8]British, [9]Asian, [10]Russian, [11]American, [12]French.");
        SendClientMessage(playerid, HCOL_WHITE, "Accents III: [13]Italian, [14]Hippie.");
        return 1;
    }
    if(accentid < 1 || accentid > 14) return SendClientMessage(playerid, -1, ""COL_ERROR"[Server]: "COL_WHITE"Invalid ID; Currently only available "COL_RED"14"COL_WHITE" Accents.");
    switch(accentid){
        case 1:{
            PlayerData[playerid][jAccent] = 1;
            SendClientMessage(playerid, HCOL_WHITE, "You have changed your accent to a common one; If you want to change it use /accent.");
        }
		case 2:{
            PlayerData[playerid][jAccent] = 2;
            SendClientMessage(playerid, HCOL_WHITE, "You have changed your accent to Colombian; If you want to change it use /accent.");
		}
		case 3:{
            PlayerData[playerid][jAccent] = 3;
            SendClientMessage(playerid, HCOL_WHITE, "You have changed your accent to Cuban; If you want to change it use /accent.");
		}
		case 4:{
            PlayerData[playerid][jAccent] = 4;
            SendClientMessage(playerid, HCOL_WHITE, "You have changed your accent to Dominican; If you want to change it use /accent.");
		}
		case 5:{
            PlayerData[playerid][jAccent] = 5;
            SendClientMessage(playerid, HCOL_WHITE, "You have changed your accent to Venezuelan; If you want to change it use /accent.");
		}
		case 6:{
            PlayerData[playerid][jAccent] = 6;
            SendClientMessage(playerid, HCOL_WHITE, "You have changed your accent to Argentinian; If you want to change it use /accent.");
		}
		case 7:{
            PlayerData[playerid][jAccent] = 7;
            SendClientMessage(playerid, HCOL_WHITE, "You have changed your accent to Uruguayan; If you want to change it use /accent.");
		}
        case 8:{
            PlayerData[playerid][jAccent] = 8;
            SendClientMessage(playerid, HCOL_WHITE, "You have changed your accent to British; If you want to change it use /accent.");
		}
		case 9:{
            PlayerData[playerid][jAccent] = 9;
            SendClientMessage(playerid, HCOL_WHITE, "You have changed your accent to Asian; If you want to change it use /accent.");
		}
		case 10:{
            PlayerData[playerid][jAccent] = 10;
            SendClientMessage(playerid, HCOL_WHITE, "You have changed your accent to Russian; If you want to change it use /accent.");
		}
		case 11:{
            PlayerData[playerid][jAccent] = 11;
            SendClientMessage(playerid, HCOL_WHITE, "You have changed your accent to American; If you want to change it use /accent.");
		}
		case 12:{
            PlayerData[playerid][jAccent] = 12;
            SendClientMessage(playerid, HCOL_WHITE, "You have changed your accent to French; If you want to change it use /accent.");
		}
		case 13:{
            PlayerData[playerid][jAccent] = 13;
            SendClientMessage(playerid, HCOL_WHITE, "You have changed your accent to Italian; If you want to change it use /accent.");
		}
		case 14:{
            PlayerData[playerid][jAccent] = 14;
            SendClientMessage(playerid, HCOL_WHITE, "You have changed your accent to Hippie; If you want to change it use /accent.");
		}
    }
    return 1;
}

CMD:me(playerid, params[]){
    if(GetPVarInt(playerid,"Logueado") == 0) return SendClientMessage(playerid, -1, ""COL_ERROR"[Server]: "COL_WHITE"You arent logged in.");
    if(isnull(params)) return SendClientMessage(playerid, HCOL_WHITE, ""COL_SERVER">> "COL_WHITE"/me (action)");
   
    format(global_str2, sizeof(global_str2), "%s %s.", PlayerName(playerid), params);
    ProxDetector(20.0, playerid, global_str2, HCOL_ME, HCOL_ME, HCOL_ME, HCOL_ME, HCOL_ME);
    return 1;
}

CMD:do(playerid, params[]){
    if(GetPVarInt(playerid,"Logueado") == 0) return SendClientMessage(playerid, -1, ""COL_ERROR"[Server]: "COL_WHITE"You arent logged in.");
    if(!isnull(params)){
        format(global_str2, sizeof(global_str2), "* %s %s.", PlayerName(playerid), params);
        return ProxDetector(20.0, playerid, global_str2, HCOL_DO, HCOL_DO, HCOL_DO, HCOL_DO, HCOL_DO);
    }
    else SendClientMessage(playerid, -1, ""COL_SERVER">> "COL_WHITE"/do <action>");
    return 1;
}

CMD:b(playerid, params[]){
    if(GetPVarInt(playerid,"Logueado") == 0) return SendClientMessage(playerid, -1, ""COL_ERROR"[Server]: "COL_WHITE"You arent logged in.");
    if(isnull(params)) return SendClientMessage(playerid, HCOL_WHITE, ""COL_SERVER">> "COL_WHITE"/b (chat ooc)");

    format(global_str2, sizeof(global_str2), "(([OOC] %s(%d): %s))", PlayerName(playerid), playerid, params);    
    ProxDetector(10.0, playerid, global_str2, HCOL_TMPGRAY, HCOL_TMPGRAY, HCOL_TMPGRAY, HCOL_TMPGRAY, HCOL_TMPGRAY);

    /* Discord: discord.inc */
    format(DiscordLog, sizeof(DiscordLog), "**(([OOC] %s(%d):))**\n```fix\n\
    %s```", PlayerName(playerid), playerid, global_str2);

    ConvertDiscordText(DiscordLog),
    SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
    return 1;
}

CMD:whisper(playerid, params[]) {return cmd_w(playerid, params);}
CMD:w(playerid, params[])
{
	new idx;
    if(GetPVarInt(playerid,"Logueado") == 0) return SendClientMessage(playerid, -1, ""COL_ERROR"[Server]: "COL_WHITE"You arent logged in.");
 	if(IsPlayerConnected(playerid))
	{
		if(sscanf(params,"u",params[0])) return SendClientMessage(playerid, -1, ""COL_SERVER">> "COL_WHITE"/w id text"),1;
		if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, -1, ""COL_ERROR"[Server]: "COL_WHITE"This player isnt connected.");
		if(params[0] == playerid) return SendClientMessage(playerid, -1, ""COL_ERROR"[Server]: "COL_WHITE"You can't whisper to yourself!");

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
			SendClientMessage(playerid, -1, ""COL_SERVER">> "COL_WHITE"/whisper id text");
			return 1;
		}
		if(!GetPlayerInRange(1.5, playerid, params[0]))
		{
			SendClientMessage(playerid, -1, ""COL_ERROR"[Server]: "COL_WHITE"There is no one near you to whisper to.");
			return 1;
		}
		format(global_str2, sizeof(global_str2), "%s whisper something in the ear to %s", PlayerName(params[0]), params[0], params[1]);
		ProxDetector(15.0, playerid, global_str2, HCOL_TMPGRAY, HCOL_TMPGRAY, HCOL_TMPGRAY, HCOL_TMPGRAY, HCOL_TMPGRAY);
		
        format(global_str2, sizeof(global_str2), "%s whispers in your ear: %s", PlayerName(playerid), playerid, params[1]);
		SendClientMessage(params[0],  HCOL_TMPGRAY, global_str2);
		
        format(global_str2, sizeof(global_str2), "You whisper in %s's ear: %s", PlayerName(params[0]), params[0], params[1]);
		SendClientMessage(playerid,  HCOL_TMPGRAY, global_str2);
	}
	return 1;
}

CMD:yells(playerid, params[]) {return cmd_y(playerid, params);}
CMD:y(playerid, params[]){
    if(GetPVarInt(playerid,"Logueado") == 0) return SendClientMessage(playerid, -1, ""COL_ERROR"[Server]: "COL_WHITE"You arent logged in.");
    if(!isnull(params)){
        format(global_str2, sizeof(global_str2), "%s yells: %s!", PlayerName(playerid), params);
        ProxDetector(30.0, playerid, global_str2,HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE);
        
        format(global_str2, sizeof(global_str2), "%s!", params);

        /* Discord: discord.inc */
        format(DiscordLog, sizeof(DiscordLog), "**%s(%d) yells:**\n```fix\n\
        %s```", PlayerName(playerid), playerid, global_str2);

        ConvertDiscordText(DiscordLog),
        SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
        return SetPlayerChatBubble(playerid,global_str2,HCOL_WHITE,60.0,5000);
    } else SendClientMessage(playerid, -1, ""COL_SERVER">> "COL_WHITE"/g text");
    return 1;
}

CMD:try(playerid, params[])
{
    if(GetPVarInt(playerid,"Logueado") == 0) return SendClientMessage(playerid, -1, ""COL_ERROR"[Server]: "COL_WHITE"You arent logged in.");
    if(AttemptAction[playerid] == 1) return SendClientMessage(playerid, -1, "Wait "COL_ERROR"10"COL_WHITE" seconds to use this command again.");
    new RandAttempt = random(2)+1;

    if(!sscanf(params, "s[128]", params[0]))
    {
        if(RandAttempt == 1)
        {
            format(global_str2, sizeof(global_str2), "* %s try %s and succeed", PlayerName(playerid), params[0]);
            ProxDetector(3.0, playerid, global_str2, HCOL_GREEN, HCOL_GREEN, HCOL_GREEN, HCOL_GREEN, HCOL_GREEN);
        }
        else
        {
            format(global_str2, sizeof(global_str2), "* %s try %s but failed.", PlayerName(playerid), params[0]);
            ProxDetector(3.0, playerid, global_str2, HCOL_RED, HCOL_RED, HCOL_RED, HCOL_RED, HCOL_RED);
        }
        AttemptAction[playerid] = 1;
        SetTimerEx("WaitingAttemp", 10000, false, "i", playerid);
    } else SendClientMessage(playerid, -1, ""COL_SERVER">> "COL_WHITE"/try <Acción>");
    return 1;
}

/*
# Service General - Commands #
*/
CMD:cure(playerid)
{
    if(GetPVarInt(playerid,"Logueado") == 0) return SendClientMessage(playerid, -1, ""COL_ERROR"[Server]: "COL_WHITE"You arent logged in.");
    
    new Float:health;
    GetPlayerHealth(playerid, health);
    if(GetPlayerMoney(playerid) < 750) return SendClientMessage(playerid, -1, "Nurse: It seems you don't have enough money!");
    if(health < 45.0)
    {
        SendClientMessage(playerid, -1, "Doctor: Apparently you have no diseases to cure, you should go eat something better.");
    }
    else
    {
        GivePlayerMoney(playerid, -750);
        SetPlayerHealth(playerid, 100);
        SendClientMessage(playerid, -1, "Doctor: Congratulations; All your diseases have been cured!");
    }
    return 1;
}