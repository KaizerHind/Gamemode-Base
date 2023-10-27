/* Test de rol por Edinson Walkeeer */

/* Plantilla:
0 = Respuesta buena. | Good Answer.
1 = Respuesta mala. | Bad Answer.

Example:
Question(playerid, X, 0); | Good Answer.
Question(playerid, X, 1); | Bad Answer.

Respuestas Actuales: Elegir cualquiera. | Preguntas a partir de la Linea: 126
*/

InitPlayerRoleTest(playerid)
{
    RolTestErrors[playerid] = 6,
    Question(playerid, 1, 0);

    return true;
}

Question(playerid, question, error)
{
    if (error)
    {
        RolTestErrors[playerid] --;

        if (question != 7)
            PlayerPlaySound(playerid, 1055, 0.0, 0.0, 0.0);
    }
    else
    {
        if (question != 7)
            PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
    }

    switch (question)
    {
        case 1:
        {
            new st_questions[500];
            strcat(st_questions, ""COL_SERVER""SERVER_NAME"\n", sizeof(st_questions));
            strcat(st_questions, "1. "COL_WHITE"Escribir Aqui.\n", sizeof(st_questions));
            strcat(st_questions, "2. "COL_WHITE"Escribir Aqui.\n", sizeof(st_questions));            
            strcat(st_questions, "3. "COL_WHITE"Escribir Aqui.\n", sizeof(st_questions));
            Dialog_Show(playerid, DialogQuestion_0, DIALOG_STYLE_TABLIST_HEADERS, ""COL_SERVER"#1 — Inserta una pregunta aqui", st_questions, "Responder", "");
        }
        case 2:
        {
            new st_questions[500];
            strcat(st_questions, ""COL_SERVER""SERVER_NAME"\n", sizeof(st_questions));
            strcat(st_questions, "1. "COL_WHITE"Escribir Aqui.\n", sizeof(st_questions));
            strcat(st_questions, "2. "COL_WHITE"Escribir Aqui.\n", sizeof(st_questions));
            strcat(st_questions, "3. "COL_WHITE"Escribir Aqui.", sizeof(st_questions));
            Dialog_Show(playerid, DialogQuestion_1, DIALOG_STYLE_TABLIST_HEADERS, ""COL_SERVER"#2 — Inserta una pregunta aqui", st_questions, "Responder", "");
        }
        case 3:
        {
            new st_questions[500];
            strcat(st_questions, ""COL_SERVER""SERVER_NAME"\n", sizeof(st_questions));
            strcat(st_questions, "1. "COL_WHITE"Escribir Aqui.\n", sizeof(st_questions));
            strcat(st_questions, "2. "COL_WHITE"Escribir Aqui.\n", sizeof(st_questions));
            strcat(st_questions, "3. "COL_WHITE"Escribir Aqui.", sizeof(st_questions));
            Dialog_Show(playerid, DialogQuestion_2, DIALOG_STYLE_TABLIST_HEADERS, ""COL_SERVER"#3 — Inserta una pregunta aqui", st_questions, "Responder", "");
        }
        case 4:
        {
            new st_questions[500];
            strcat(st_questions, ""COL_SERVER""SERVER_NAME"\n", sizeof(st_questions));
            strcat(st_questions, "1. "COL_WHITE"Escribir Aqui.\n", sizeof(st_questions));
            strcat(st_questions, "2. "COL_WHITE"Escribir Aqui.\n", sizeof(st_questions));
            strcat(st_questions, "3. "COL_WHITE"Escribir Aqui.", sizeof(st_questions));
            Dialog_Show(playerid, DialogQuestion_3, DIALOG_STYLE_TABLIST_HEADERS, ""COL_SERVER"#4 — Inserta una pregunta aqui", st_questions, "Responder", "");
        }
        case 5:
        {
            new st_questions[500];
            strcat(st_questions, ""COL_SERVER""SERVER_NAME"\n", sizeof(st_questions));
            strcat(st_questions, "1. "COL_WHITE"Escribir Aqui.\n", sizeof(st_questions));
            strcat(st_questions, "2. "COL_WHITE"Escribir Aqui.\n", sizeof(st_questions));
            strcat(st_questions, "3. "COL_WHITE"Escribir Aqui.", sizeof(st_questions));
            Dialog_Show(playerid, DialogQuestion_4, DIALOG_STYLE_TABLIST_HEADERS, ""COL_SERVER"#5 — Inserta una pregunta aqui", st_questions, "Responder", "");
        }
        case 6:
        {
            new st_questions[500];
            strcat(st_questions, ""COL_SERVER""SERVER_NAME"\n", sizeof(st_questions));
            strcat(st_questions, "1. "COL_WHITE"Escribir Aqui.\n", sizeof(st_questions));
            strcat(st_questions, "2. "COL_WHITE"Escribir Aqui.\n", sizeof(st_questions));
            strcat(st_questions, "3. "COL_WHITE"Escribir Aqui.", sizeof(st_questions));
            Dialog_Show(playerid, DialogQuestion_5, DIALOG_STYLE_TABLIST_HEADERS, ""COL_SERVER"#6 — Inserta una pregunta aqui", st_questions, "Ver Resultado", "");
        }
        case 7:
        {
            if (RolTestErrors[playerid] == 6)
            {
              /* Discord: discord.inc */
                format(DiscordLog, sizeof(DiscordLog), "(( `%s` ha aprobado el Test de Rol. ))",  PlayerName(playerid));
                ConvertDiscordText(DiscordLog);
                SendRolTestEmbedMessage(DCHANNEL_LOG, DiscordLog);

                /* Discord: discord.inc */
                format(DiscordLog, sizeof(DiscordLog), "(( `%s` va a comenzar a registrar su Cuenta en el Servidor. **[Part 2/3]**))", PlayerName(playerid));
                ConvertDiscordText(DiscordLog),
                SendRegisterEmbedMessage(DCHANNEL_LOG, DiscordLog);

                format(global_str, sizeof(global_str), ""COL_WHITE"Bienvenido a "COL_SERVER""SERVER_PROJECT" "COL_SERVER"%s"COL_WHITE"! Felicidades por aprobar el Examen de Rol.\nEsperamos te diviertas dentro de la Comunidad, no olvides respetar las Reglas\ny jugar de manera sana, cualquier falta puede conllevar a una sancion.\n\nSin nada mas que decir; Procedamos a tomar tus datos.\n\nIngresa una contraseña para registrar tu cuenta.", PlayerName(playerid));
                Dialog_Show(playerid, dRegistro, DIALOG_STYLE_PASSWORD, mHeader, global_str, ""COL_WHITE"Aceptar", "");
            }
            else
            {
                format(st_FailTest, sizeof(st_FailTest), ""COL_ERROR"Has fallado el Examen; "COL_WHITE"Intenta de nuevo.\nAciertos: "COL_WHITE"%d/"COL_SERVER"%d", 0 + RolTestErrors[playerid], 6);
                SendClientMessage(playerid, -1, st_FailTest);

                /* Discord: discord.inc */
                format(DiscordLog, sizeof(DiscordLog), "(( `%s` ha fallado ah realizar el Test de Rol; Comenzara de nuevo. ))\nAciertos: `%d/%d`",  PlayerName(playerid), RolTestErrors[playerid] + 0, 6);
                ConvertDiscordText(DiscordLog);
                SendRolTestEmbedMessage(DCHANNEL_LOG, DiscordLog);
                return InitPlayerRoleTest(playerid);
            }
        }
    }
    return true;
}

Dialog:DialogQuestion_0(playerid, response, listitem, inputtext[])
{
    if (!response) return RestartRoleTest(playerid);
    switch (listitem)
    {
        case 0: Question(playerid, 2, 0);
        case 1: Question(playerid, 2, 0);
        case 2: Question(playerid, 2, 0);
    }
    return 0;
}

Dialog:DialogQuestion_1(playerid, response, listitem, inputtext[])
{
    if (!response) return RestartRoleTest(playerid);
    switch (listitem)
    {
        case 0: Question(playerid, 3, 0);
        case 1: Question(playerid, 3, 0);
        case 2: Question(playerid, 3, 0);
    }
    return 0;
}

Dialog:DialogQuestion_2(playerid, response, listitem, inputtext[])
{
    if (!response) return RestartRoleTest(playerid);
    switch (listitem)
    {
        case 0: Question(playerid, 4, 0);
        case 1: Question(playerid, 4, 0);
        case 2: Question(playerid, 4, 0);
    }
    return 0;
}

Dialog:DialogQuestion_3(playerid, response, listitem, inputtext[])
{
    if (!response) return RestartRoleTest(playerid);
    switch (listitem)
    {
        case 0: Question(playerid, 5, 0);
        case 1: Question(playerid, 5, 0);
        case 2: Question(playerid, 5, 0);
    }
    return 0;
}

Dialog:DialogQuestion_4(playerid, response, listitem, inputtext[])
{
    if (!response) return RestartRoleTest(playerid);
    switch (listitem)
    {
        case 0: Question(playerid, 6, 0);
        case 1: Question(playerid, 6, 0);
        case 2: Question(playerid, 6, 0);
    }
    return 0;
}

Dialog:DialogQuestion_5(playerid, response, listitem, inputtext[])
{
    if (!response) return RestartRoleTest(playerid);
    switch (listitem)
    {
        case 0: Question(playerid, 7, 0);
        case 1: Question(playerid, 7, 0);
        case 2: Question(playerid, 7, 0);
    }
    return 0;
}