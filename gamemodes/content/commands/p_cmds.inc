/*
:......::::........::..::::..::........::..:::::..::..:::::..::........:::::......:::..:::::..::........::::......:::
:'######:::'########:'##::: ##:'########:'########:::::'###::::'##::::::::::'######::'##::::'##:'########:::'######::
'##... ##:: ##.....:: ###:: ##: ##.....:: ##.... ##:::'## ##::: ##:::::::::'##... ##: ###::'###: ##.... ##:'##... ##:
 ##:::..::: ##::::::: ####: ##: ##::::::: ##:::: ##::'##:. ##:: ##::::::::: ##:::..:: ####'####: ##:::: ##: ##:::..::
 ##::'####: ######::: ## ## ##: ######::: ########::'##:::. ##: ##::::::::: ##::::::: ## ### ##: ##:::: ##:. ######::
 ##::: ##:: ##...:::: ##. ####: ##...:::: ##.. ##::: #########: ##::::::::: ##::::::: ##. #: ##: ##:::: ##::..... ##:
 ##::: ##:: ##::::::: ##:. ###: ##::::::: ##::. ##:: ##.... ##: ##::::::::: ##::: ##: ##:.:: ##: ##:::: ##:'##::: ##:
. ######::: ########: ##::. ##: ########: ##:::. ##: ##:::: ##: ########:::. ######:: ##:::: ##: ########::. ######::
:......::::........::..::::..::........::..:::::..::..:::::..::........:::::......:::..:::::..::........::::......:::
*/

cmd:dicc(playerid){ Dialog_Show(playerid, 9990, DIALOG_STYLE_MSGBOX, mHeader, "\
    {7bbfcf}� Diccionario de Errores en respuesta a comandos\n\n\
    {7bbfcf}[x] "COL_WHITE"Invalid Error "COL_E_CODE"[00] "COL_WHITE"/ El Usuario no ha hecho spawn en el Servidor.\n\
    {7bbfcf}[x] "COL_WHITE"Invalid Error "COL_E_CODE"[01] "COL_WHITE"/ Usuario Desconectado.\n\
    {7bbfcf}[x] "COL_WHITE"Invalid Error "COL_E_CODE"[02] "COL_WHITE"/ Flood/Temporizador de Mensajes. (5/10 segs)\n\
    {7bbfcf}[x] "COL_WHITE"Invalid Error "COL_E_CODE"[03] "COL_WHITE"/ No se encontro a nadie cerca de ti.\n\
    {7bbfcf}[x] "COL_WHITE"Invalid Error "COL_E_CODE"[04] "COL_WHITE"/ El Usuario se encuentra en un vehiculo.\n\
    {7bbfcf}[x] "COL_WHITE"Invalid Error "COL_E_CODE"[05] "COL_WHITE"/ El Usuario no se encuentra muerto.\n\
    {7bbfcf}[x] "COL_WHITE"Invalid Error "COL_E_CODE"[06] "COL_WHITE"/ No puedes aplicar comandos a ti mismo.\
", "Aceptar", ""); return 1;}

cmd:acento(playerid, params[]){
    new accentid;
    if(GetPVarInt(playerid,"Logueado") == 0) return ServerAlert(playerid, "[00]");
    if(AttemptAction[playerid] == 1) return ServerAlert(playerid, "[02] ");

    if(sscanf(params, "d", accentid)){
        DefaultCommand(playerid, "/acento [1-14]");
        ClientMessage(playerid, "Acentos I:   [1]Normal, [2]Colombiano, [3]Cubano, [4]Dominicano, [5]Venezolano, [6]Argentino.");
        ClientMessage(playerid, "Acentos II:  [7]Uruguayo, [8]Britanico, [9]Asiatico, [10]Ruso, [11]Americano, [12]Frances.");
        ClientMessage(playerid, "Acentos III: [13]Italiano, [14]Hippie.");
        return 1;
    }

    AttemptAction[playerid] = 1;
    SetTimerEx("WaitingAttemp", 5000, false, "i", playerid);

    if(accentid < 1 || accentid > 14) return ServerAlert(playerid, "ID Invalida; Actualmente solo hay disponibles "COL_RED"14"COL_WHITE" Acentos.");
    switch(accentid){
        case 1:{
            PlayerData[playerid][jAccent] = 1;
            ClientMessage(playerid, "Has modificado tu acento a uno comun; Si deseas cambiarlo usa /acento.");
        }
        case 2:{
            PlayerData[playerid][jAccent] = 2;
            ClientMessage(playerid, "Has modificado tu acento a Colombiano; Si deseas cambiarlo usa /acento.");
        }
        case 3:{
            PlayerData[playerid][jAccent] = 3;
            ClientMessage(playerid, "Has modificado tu acento a Cubano; Si deseas cambiarlo usa /acento.");
        }
        case 4:{
            PlayerData[playerid][jAccent] = 4;
            ClientMessage(playerid, "Has modificado tu acento a Dominicano; Si deseas cambiarlo usa /acento.");
        }
        case 5:{
            PlayerData[playerid][jAccent] = 5;
            ClientMessage(playerid, "Has modificado tu acento a Venezolano; Si deseas cambiarlo usa /acento.");
        }
        case 6:{
            PlayerData[playerid][jAccent] = 6;
            ClientMessage(playerid, "Has modificado tu acento a Argentino; Si deseas cambiarlo usa /acento.");
        }
        case 7:{
            PlayerData[playerid][jAccent] = 7;
            ClientMessage(playerid, "Has modificado tu acento a Uruguayo; Si deseas cambiarlo usa /acento.");
        }
        case 8:{
            PlayerData[playerid][jAccent] = 8;
            ClientMessage(playerid, "Has modificado tu acento a Britanico; Si deseas cambiarlo usa /acento.");
        }
        case 9:{
            PlayerData[playerid][jAccent] = 9;
            ClientMessage(playerid, "Has modificado tu acento a Asiatico; Si deseas cambiarlo usa /acento.");
        }
        case 10:{
            PlayerData[playerid][jAccent] = 10;
            ClientMessage(playerid, "Has modificado tu acento a Ruso; Si deseas cambiarlo usa /acento.");
        }
        case 11:{
            PlayerData[playerid][jAccent] = 11;
            ClientMessage(playerid, "Has modificado tu acento a Americano; Si deseas cambiarlo usa /acento.");
        }
        case 12:{
            PlayerData[playerid][jAccent] = 12;
            ClientMessage(playerid, "Has modificado tu acento a Frances; Si deseas cambiarlo usa /acento.");
        }
        case 13:{
            PlayerData[playerid][jAccent] = 13;
            ClientMessage(playerid, "Has modificado tu acento a Italiano; Si deseas cambiarlo usa /acento.");
        }
        case 14:{
            PlayerData[playerid][jAccent] = 14;
            ClientMessage(playerid, "Has modificado tu acento a Hippie; Si deseas cambiarlo usa /acento.");
        }
    }
    return 1;
}alias:acento("ac")

    cmd:curar(playerid, params[]){
    new Float:health;
    if(GetPVarInt(playerid,"Logueado") == 0) return ServerAlert(playerid, "[00]");
    //if(!IsPlayerInRangeOfPoint(playerid, 2.5, Float:X, Float:Y, Float:Z))
    GetPlayerHealth(playerid, health);

    if(GetPlayerMoney(playerid) < 750) return ClientMessage(playerid, "Enfemera: !Al parecer no tienes el dinero suficiente!");
    if(health > 45.0)
    {
        ClientMessage(playerid, "[NPC] Medico: Al parecer no tienes enfermedades que curar, deberias ir a comer algo mejor.");
    }
    else
    {
        acc_GivePlayerMoney(playerid, -750);
        SetPlayerHealth(playerid, 100);
        ClientMessage(playerid, "[NPC] Medico: �Enhorabuena; Hemos tratado tus heridas, ya pareces estar en mejor estado!");
        save_int_mysql("users", "Money",  PlayerData[playerid][jName], PlayerData[playerid][jMoney]);
    }
    return 1;
}

/*
..:::::..:::.......:::........:::::......:::..:::::..::........:::
'########:::'#######::'##::::::::::'######::'##::::'##:'########::
 ##.... ##:'##.... ##: ##:::::::::'##... ##: ###::'###: ##.... ##:
 ##:::: ##: ##:::: ##: ##::::::::: ##:::..:: ####'####: ##:::: ##:
 ########:: ##:::: ##: ##::::::::: ##::::::: ## ### ##: ##:::: ##:
 ##.. ##::: ##:::: ##: ##::::::::: ##::::::: ##. #: ##: ##:::: ##:
 ##::. ##:: ##:::: ##: ##::::::::: ##::: ##: ##:.:: ##: ##:::: ##:
 ##:::. ##:. #######:: ########:::. ######:: ##:::: ##: ########::
..:::::..:::.......:::........:::::......:::..:::::..::........:::
*/

cmd:me(playerid, params[]){
    if(GetPVarInt(playerid,"Logueado") == 0) return ServerAlert(playerid, "[00]");
    if(isnull(params)) return DefaultCommand(playerid, "/me (acci�n)");

    format(global_str2, sizeof(global_str2), "%s %s.", PlayerName(playerid), params);
    AutoRol(playerid, global_str2);
    return 1;
}

cmd:do(playerid, params[]){
    if(GetPVarInt(playerid,"Logueado") == 0) return ServerAlert(playerid, "[00]");
    if(!isnull(params)){
    format(global_str2, sizeof(global_str2), "* %s %s.", PlayerName(playerid), params);
    return ProxDetector(20.0, playerid, global_str2, HCOL_DO, HCOL_DO, HCOL_DO, HCOL_DO, HCOL_DO);
    }
    else DefaultCommand(playerid, "/do <Acci�n>");
    return 1;
}

cmd:b(playerid, params[]){
    if(GetPVarInt(playerid,"Logueado") == 0) return ServerAlert(playerid, "[00]");
    if(AttemptAction[playerid] == 1) return ServerAlert(playerid, "[02]");
    if(isnull(params)) return DefaultCommand(playerid, "/b (chat ooc)");

    AttemptAction[playerid] = 1;
    SetTimerEx("WaitingAttemp", 5000, false, "i", playerid);

    format(global_str2, sizeof(global_str2), "(([OOC] %s(%d): %s))", PlayerName(playerid), playerid, params);    
    ProxDetector(10.0, playerid, global_str2, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE);

    /* Discord: discord.inc */
    format(DiscordLog, sizeof(DiscordLog), "**(([OOC] %s(%d):))**\n```fix\n\
    %s```", PlayerName(playerid), playerid, global_str2);

    ConvertDiscordText(DiscordLog),
    SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
    return 1;
}

cmd:susurrar(playerid, params[]){
    new userid, text[128];
    if(GetPVarInt(playerid,"Logueado") == 0) return ServerAlert(playerid, "[00]");
    {
        if (sscanf(params, "us[128]", userid, text)) return DefaultCommand(playerid, "/s id texto"),1;
        if (userid == INVALID_PLAYER_ID || !GetPlayerInRange(1.0, playerid, userid)) return ServerAlert(playerid, "[03]");
        if (userid == playerid) return ServerAlert(playerid, "[06]");

        if (strlen(text) > 75)
        {
            UserMessage(userid, HCOL_TMPGRAY, "%s te ha susurrado al o�do: %.75s ...", PlayerName(playerid), text);
            UserMessage(userid, HCOL_TMPGRAY, "... %s", text[75]);

            UserMessage(userid, HCOL_TMPGRAY, "Le has susurrado al o�do a \"%s\": %.75s ...", PlayerName(userid), text);
            UserMessage(userid, HCOL_TMPGRAY, "... %s", text[75]);
        }
        else
        {
            UserMessage(userid, HCOL_TMPGRAY, "%s te ha susurrado al o�do: %s", PlayerName(playerid), text);
            UserMessage(playerid, HCOL_TMPGRAY, "Le has susurrado al o�do a \"%s\": %s", PlayerName(userid), text);


            format(global_str2, sizeof(global_str2), "susurr� algo en el o�do de %s.", PlayerName(userid));
            SetPlayerChatBubble(playerid, global_str2, HCOL_ME, 60.0,5000);

            /* Discord: a.inc */
            format(DiscordLog, sizeof(DiscordLog), "**%s le susurra al oido a %s: %s**\n```fix\n\
            %s```", PlayerName(playerid), PlayerName(userid), text, global_str2);

            ConvertDiscordText(DiscordLog),
            SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
        }
    }
    return 1;
}alias:susurrar("s", "susurro", "oido", "murmurar")

cmd:gritar(playerid, params[]) {
    if (GetPVarInt(playerid, "Logueado") == 0) return ServerAlert(playerid, "[00]");
    if (!isnull(params)) {
        format(global_str2, sizeof(global_str2), "%s grita: %s!", PlayerName(playerid), params);
        ProxDetector(30.0, playerid, global_str2, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE, HCOL_WHITE);

        format(global_str2, sizeof(global_str2), "%s!", params);

        /* Discord: discord.inc */
        format(DiscordLog, sizeof(DiscordLog), "**%s(%d) grita:**\n```fix\n\
        %s```", PlayerName(playerid), playerid, global_str2);

        ConvertDiscordText(DiscordLog),
        SendTextEmbedMessage(DCHANNEL_CHAT, DiscordLog);
        return SetPlayerChatBubble(playerid, global_str2, HCOL_WHITE, 60.0, 5000);
    } else DefaultCommand(playerid, "/g texto");
    return 1;
}
alias:gritar("g")
cmd:intentar(playerid, params[]){
    if(GetPVarInt(playerid,"Logueado") == 0) return ServerAlert(playerid, "[00]");
    if(AttemptAction[playerid] == 1) return ServerAlert(playerid, "[02]");
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
    } else DefaultCommand(playerid, "/intentar <Acci�n>");
    return 1;
}

/*
..:::::..::..::::..::....::..:::::..::..:::::..:::::..:::::....:::.......:::..::::..:::......:::
:::'###::::'##::: ##:'####:'##::::'##::::'###::::'########:'####::'#######::'##::: ##::'######::
::'## ##::: ###:: ##:. ##:: ###::'###:::'## ##:::... ##..::. ##::'##.... ##: ###:: ##:'##... ##:
:'##:. ##:: ####: ##:: ##:: ####'####::'##:. ##::::: ##::::: ##:: ##:::: ##: ####: ##: ##:::..::
'##:::. ##: ## ## ##:: ##:: ## ### ##:'##:::. ##:::: ##::::: ##:: ##:::: ##: ## ## ##:. ######::
 #########: ##. ####:: ##:: ##. #: ##: #########:::: ##::::: ##:: ##:::: ##: ##. ####::..... ##:
 ##.... ##: ##:. ###:: ##:: ##:.:: ##: ##.... ##:::: ##::::: ##:: ##:::: ##: ##:. ###:'##::: ##:
 ##:::: ##: ##::. ##:'####: ##:::: ##: ##:::: ##:::: ##::::'####:. #######:: ##::. ##:. ######::
..:::::..::..::::..::....::..:::::..::..:::::..:::::..:::::....:::.......:::..::::..:::......:::
*/

cmd:sex(playerid, params[]) //fase beta, aun tiene problemas
{
    static
    userid,
    type;

    if (sscanf(params, "ud", userid, type)) return DefaultCommand(playerid, "/animinvite <id/nombre> <1-6>.");
    if (userid == INVALID_PLAYER_ID || !GetPlayerInRange(3.0, playerid, userid)) return ClientMessage(playerid, "No est� conectado y/o suficientemente cerca de ti.");
    if (userid == playerid) return ServerAlert(playerid, "[06]");
    if (type < 1 || type > 6) return DefaultCommand(playerid, "/sex <id/nombre> <1-6>.");

    PlayerData[userid][SHAKE_OFFER] = playerid,
    PlayerData[userid][SHAKE_OFFER_TYPE] = type;

    UserMessage(userid, -1, "%s quiere tener intimidad contigo.", PlayerName(playerid));
    format(global_str2, sizeof(global_str2), "\"/aceptar pose\" o simplemente ignora la petici�n."); ClientMessage(userid, global_str2);
    UserMessage(playerid, -1, "Petici�n de intimidad enviada. Espera a que %s responda.", PlayerName(userid));


    return 1;
}alias:sex("sexinv", "sinv", "sexinvite", "sexrol")

cmd:aceptar(playerid, params[])
{
    if (isnull(params))
    {
        DefaultCommand(playerid, "/aceptar <pose>");
        return true;
    }

    else if (!strcmp(params, "pose", true) && PlayerData[playerid][SHAKE_OFFER] != INVALID_PLAYER_ID)
    {
        new
            parnertid = PlayerData[playerid][SHAKE_OFFER],
            type = PlayerData[playerid][SHAKE_OFFER_TYPE]
            ;

        if (!GetPlayerInRange(3.0, playerid, parnertid)) return SendClientMessage(playerid, HCOL_ERROR, "No est�s lo suficientemente cerca del jugador.");
        if (type > 6) return SendClientMessage(playerid, HCOL_ERROR, "No te ofrecieron un saludo.");

        SetPlayerToFacePlayer(playerid, parnertid),
        SetPlayerToFacePlayer(parnertid, playerid);

        PlayerData[playerid][SHAKE_OFFER] = INVALID_PLAYER_ID,
        PlayerData[playerid][SHAKE_OFFER_TYPE] = INVALID;

        switch (type)
        {
            case 1:
            {
                ApplyAnimation(playerid, "SEX", "SEX_1TO2_P", 1.0, 1, 1, 1, 0, 0, 1);
                ApplyAnimation(parnertid, "SEX", "SEX_1TO2_W", 1.0, 1, 1, 1, 0, 0, 1);
            }
            case 2:
            {
                ApplyAnimation(playerid, "SEX", "SEX_1_CUM_P", 1.0, 1, 1, 1, 0, 0, 1);
                ApplyAnimation(parnertid, "SEX", "SEX_1_CUM_W", 1.0, 1, 1, 1, 0, 0, 1);
            }
            case 3:
            {
                ApplyAnimation(playerid, "SEX", "SEX_1_FAIL_P", 1.0, 1, 1, 1, 0, 0, 1);
                ApplyAnimation(parnertid, "SEX", "SEX_1_FAIL_W", 1.0, 1, 1, 1, 0, 0, 1);
            }
            case 4:
            {
                ApplyAnimation(playerid, "SEX", "SEX_1_P", 1.0, 1, 1, 1, 0, 0, 1);
                ApplyAnimation(parnertid, "SEX", "SEX_1_W", 1.0, 1, 1, 1, 0, 0, 1);
            }
            case 5:
            {
                ApplyAnimation(playerid, "SEX", "SEX_2TO3_P", 1.0, 1, 1, 1, 0, 0, 1);
                ApplyAnimation(parnertid, "SEX", "SEX_2TO3_W", 1.0, 1, 1, 1, 0, 0, 1);
            }
            case 6:
            {
                ApplyAnimation(playerid, "SEX", "SEX_2_FAIL_P", 1.0, 1, 1, 1, 0, 0, 1);
                ApplyAnimation(parnertid, "SEX", "SEX_2_FAIL_W", 1.0, 1, 1, 1, 0, 0, 1);
            }
        }
        format(global_str2, sizeof(global_str2), "le hace un oral a %s.", PlayerName(parnertid)),
        ClientMessage(playerid, global_str2);

        format(global_str2, sizeof(global_str2), "%s comienza a hacerte un oral.", PlayerName(playerid)),
        ClientMessage(playerid, global_str2);
        return 1;
    }
    else
    {
        ClientMessage(playerid, "/aceptar <pose>");
    }
    return 1;
}