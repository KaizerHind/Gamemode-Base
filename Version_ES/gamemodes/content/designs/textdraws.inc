public OnGameModeInit()
{
    /*# Nombre del Servidor #*/
    TD_SERVERNAME[0] = TextDrawCreate(71.600036, 304.986785, "NAME SERVER");
    TextDrawLetterSize(TD_SERVERNAME[0], 0.363599, 1.400889);
    TextDrawTextSize(TD_SERVERNAME[0], 0.000000, 272.000000);
    TextDrawAlignment(TD_SERVERNAME[0], 2);
    TextDrawColor(TD_SERVERNAME[0], -1);
    TextDrawSetShadow(TD_SERVERNAME[0], 0);
    TextDrawSetOutline(TD_SERVERNAME[0], -1);
    TextDrawBackgroundColor(TD_SERVERNAME[0], 255);
    TextDrawFont(TD_SERVERNAME[0], 3);
    TextDrawSetProportional(TD_SERVERNAME[0], true);

    TD_SERVERNAME[1] = TextDrawCreate(70.000038, 318.887634, "Roleplay");
    TextDrawLetterSize(TD_SERVERNAME[1], 0.363599, 1.400889);
    TextDrawTextSize(TD_SERVERNAME[1], 0.000000, 272.000000);
    TextDrawAlignment(TD_SERVERNAME[1], 2);
    TextDrawColor(TD_SERVERNAME[1], -1);
    TextDrawSetShadow(TD_SERVERNAME[1], 0);
    TextDrawSetOutline(TD_SERVERNAME[1], -1);
    TextDrawBackgroundColor(TD_SERVERNAME[1], 255);
    TextDrawFont(TD_SERVERNAME[1], 3);
    TextDrawSetProportional(TD_SERVERNAME[1], true);

    /*# Mensaje que se mostrara al Errar un comando. #*/
    tdError[0] = TextDrawCreate(114.899940, 359.144378, "RedBox");
    TextDrawLetterSize(tdError[0], 0.000000, 3.000003);
    TextDrawTextSize(tdError[0], 122.699943, 0.000000);
    TextDrawAlignment(tdError[0], 1);
    TextDrawColor(tdError[0], -1);
    TextDrawUseBox(tdError[0], true);
    TextDrawBoxColor(tdError[0], -1237303066);
    TextDrawSetShadow(tdError[0], 0);
    TextDrawBackgroundColor(tdError[0], 255);
    TextDrawFont(tdError[0], 1);
    TextDrawSetProportional(tdError[0], true);

    tdError[1] = TextDrawCreate(125.299774, 359.144378, "BlackBox");
    TextDrawLetterSize(tdError[1], 0.000000, 3.000003);
    TextDrawTextSize(tdError[1], 250.000000, 0.000000);
    TextDrawAlignment(tdError[1], 1);
    TextDrawColor(tdError[1], -1);
    TextDrawUseBox(tdError[1], true);
    TextDrawBoxColor(tdError[1], 230);
    TextDrawSetShadow(tdError[1], 0);
    TextDrawBackgroundColor(tdError[1], 255);
    TextDrawFont(tdError[1], 1);
    TextDrawSetProportional(tdError[1], true);

    tdError[2] = TextDrawCreate(127.599998, 363.226745, "Faltan Parametros o ingresaste un Comando es incorrecto.");
    TextDrawLetterSize(tdError[2], 0.217200, 1.027555);
    TextDrawTextSize(tdError[2], 246.000000, 0.000000);
    TextDrawAlignment(tdError[2], 1);
    TextDrawColor(tdError[2], -1);
    TextDrawSetShadow(tdError[2], 0);
    TextDrawBackgroundColor(tdError[2], 255);
    TextDrawFont(tdError[2], 1);
    TextDrawSetProportional(tdError[2], true);

    /* ############### DON TOUCH ############### */
    #if defined ongame_td_OnGameModeInit
        return ongame_td_OnGameModeInit();
    #else
        return 1;
    #endif
}
#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif

#define OnGameModeInit ongame_td_OnGameModeInit
#if defined ongame_td_OnGameModeInit
    forward ongame_td_OnGameModeInit();
#endif

stock LoadPlayerTextdraw(i)
{
	return 1;
}