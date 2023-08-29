/* Test de rol por Edinson Walkeeer */
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
            strcat(st_questions, "1. "COL_WHITE"Message Option Here\n", sizeof(st_questions));
            strcat(st_questions, "2. "COL_WHITE"Message Option Here\n", sizeof(st_questions));            
            strcat(st_questions, "3. "COL_WHITE"Message Option Here\n", sizeof(st_questions));
            Dialog_Show(playerid, DialogQuestion_0, DIALOG_STYLE_TABLIST_HEADERS, ""COL_SERVER"#1 — Title Here", st_questions, "Reply", "");
        }
        case 2:
        {
            new st_questions[500];
            strcat(st_questions, ""COL_SERVER""SERVER_NAME"\n", sizeof(st_questions));
            strcat(st_questions, "1. "COL_WHITE"Message Option Here\n", sizeof(st_questions));
            strcat(st_questions, "2. "COL_WHITE"Message Option Here\n", sizeof(st_questions));
            strcat(st_questions, "3. "COL_WHITE"Message Option Here", sizeof(st_questions));
            Dialog_Show(playerid, DialogQuestion_1, DIALOG_STYLE_TABLIST_HEADERS, ""COL_SERVER"#2 — Title Here", st_questions, "Reply", "");
        }
        case 3:
        {
            new st_questions[500];
            strcat(st_questions, ""COL_SERVER""SERVER_NAME"\n", sizeof(st_questions));
            strcat(st_questions, "1. "COL_WHITE"Message Option Here\n", sizeof(st_questions));
            strcat(st_questions, "2. "COL_WHITE"Message Option Here\n", sizeof(st_questions));
            strcat(st_questions, "3. "COL_WHITE"Message Option Here", sizeof(st_questions));
            Dialog_Show(playerid, DialogQuestion_2, DIALOG_STYLE_TABLIST_HEADERS, ""COL_SERVER"#3 — Title Here", st_questions, "Reply", "");
        }
        case 4:
        {
            new st_questions[500];
            strcat(st_questions, ""COL_SERVER""SERVER_NAME"\n", sizeof(st_questions));
            strcat(st_questions, "1. "COL_WHITE"Message Option Here\n", sizeof(st_questions));
            strcat(st_questions, "2. "COL_WHITE"Message Option Here\n", sizeof(st_questions));
            strcat(st_questions, "3. "COL_WHITE"Message Option Here", sizeof(st_questions));
            Dialog_Show(playerid, DialogQuestion_3, DIALOG_STYLE_TABLIST_HEADERS, ""COL_SERVER"#4 — Title Here", st_questions, "Reply", "");
        }
        case 5:
        {
            new st_questions[500];
            strcat(st_questions, ""COL_SERVER""SERVER_NAME"\n", sizeof(st_questions));
            strcat(st_questions, "1. "COL_WHITE"Message Option Here\n", sizeof(st_questions));
            strcat(st_questions, "2. "COL_WHITE"Message Option Here\n", sizeof(st_questions));
            strcat(st_questions, "3. "COL_WHITE"Message Option Here", sizeof(st_questions));
            Dialog_Show(playerid, DialogQuestion_4, DIALOG_STYLE_TABLIST_HEADERS, ""COL_SERVER"#5 — Title Here", st_questions, "Reply", "");
        }
        case 6:
        {
            new st_questions[500];
            strcat(st_questions, ""COL_SERVER""SERVER_NAME"\n", sizeof(st_questions));
            strcat(st_questions, "1. "COL_WHITE"Message Option Here\n", sizeof(st_questions));
            strcat(st_questions, "2. "COL_WHITE"Message Option Here\n", sizeof(st_questions));
            strcat(st_questions, "3. "COL_WHITE"Message Option Here", sizeof(st_questions));
            Dialog_Show(playerid, DialogQuestion_5, DIALOG_STYLE_TABLIST_HEADERS, ""COL_SERVER"#6 — Title Here", st_questions, "Resultados", "");
        }
        case 7:
        {
            if (RolTestErrors[playerid] == 6)
            {
              /* Discord: discord.inc */
                format(DiscordLog, sizeof(DiscordLog), "(( `%s` Has passed the Role Test. ))",  PlayerName(playerid));
                ConvertDiscordText(DiscordLog);
                SendRolTestEmbedMessage(DCHANNEL_LOG, DiscordLog);

                /* Discord: discord.inc */
                format(DiscordLog, sizeof(DiscordLog), "(( `%s` You have started with the registration of your Account on the Server. **[Part 2/3]**))", PlayerName(playerid));
                ConvertDiscordText(DiscordLog),
                SendRegisterEmbedMessage(DCHANNEL_LOG, DiscordLog);

                format(global_str, sizeof(global_str), ""COL_WHITE"Welcome to "COL_SERVER""SERVER_PROJECT" "COL_SERVER"%s"COL_WHITE"! Congratulations on passing the Role-playing Exam.\nWe hope you have fun within the Community, don't forget to respect the Rules\nand play healthy, any failure can lead to a sanction.\n\nWithout anything else to say, let's proceed to take your data.\n\nEnter a password to register your account.", PlayerName(playerid));
                Dialog_Show(playerid, dRegistro, DIALOG_STYLE_PASSWORD, mHeader, global_str, ""COL_WHITE"Aceptar", "");
            }
            else
            {
                format(st_FailTest, sizeof(st_FailTest), ""COL_ERROR"You have failed the Exam; "COL_WHITE"Try again.\nHits: "COL_WHITE"%d/"COL_SERVER"%d", 0 + RolTestErrors[playerid], 6);
                SendClientMessage(playerid, -1, st_FailTest);

                /* Discord: discord.inc */
                format(DiscordLog, sizeof(DiscordLog), "(( `%s` he has failed to perform the Role Test; It will start again. ))\nHits: `%d/%d`",  PlayerName(playerid), RolTestErrors[playerid] + 0, 6);
                ConvertDiscordText(DiscordLog);
                SendRolTestEmbedMessage(DCHANNEL_LOG, DiscordLog);
                return InitPlayerRoleTest(playerid);
            }
        }
    }
    return true;
}

/* Plantilla:
0 = Respuesta buena. | Good Answer.
1 = Respuesta mala. | Bad Answer.

Example:
Question(playerid, X, 0); | Good Answer.
Question(playerid, X, 1); | Bad Answer.

Answes Questions: 2, 1-3, 2, 1, 2, 3.
*/

Dialog:DialogQuestion_0(playerid, response, listitem, inputtext[])
{
    if (!response)
    {
        SendClientMessage(playerid, -1, "Has omitido de la pregunta "COL_RED"#1.");
    }

    switch (listitem)
    {
        case 0: Question(playerid, 2, 0);
        case 1: Question(playerid, 2, 0);
        case 2: Question(playerid, 2, 0);
    }
}

Dialog:DialogQuestion_1(playerid, response, listitem, inputtext[])
{
    if (!response)
    {
        SendClientMessage(playerid, -1, "Has omitido de la pregunta "COL_RED"#2.");
    }

    switch (listitem)
    {
        case 0: Question(playerid, 3, 0);
        case 1: Question(playerid, 3, 0);
        case 2: Question(playerid, 3, 0);
    }
}

Dialog:DialogQuestion_2(playerid, response, listitem, inputtext[])
{
    if (!response)
    {
        SendClientMessage(playerid, -1, "Has omitido de la pregunta "COL_RED"#3.");
    }

    switch (listitem)
    {
        case 0: Question(playerid, 4, 0);
        case 1: Question(playerid, 4, 0);
        case 2: Question(playerid, 4, 0);
    }
}

Dialog:DialogQuestion_3(playerid, response, listitem, inputtext[])
{
    if (!response)
    {
        SendClientMessage(playerid, -1, "Has omitido de la pregunta "COL_RED"#4.");
    }

    switch (listitem)
    {
        case 0: Question(playerid, 5, 0);
        case 1: Question(playerid, 5, 0);
        case 2: Question(playerid, 5, 0);
    }
}

Dialog:DialogQuestion_4(playerid, response, listitem, inputtext[])
{
    if (!response)
    {
        SendClientMessage(playerid, -1, "Has omitido de la pregunta "COL_RED"#5.");
    }

    switch (listitem)
    {
        case 0: Question(playerid, 6, 0);
        case 1: Question(playerid, 6, 0);
        case 2: Question(playerid, 6, 0);
    }
}

Dialog:DialogQuestion_5(playerid, response, listitem, inputtext[])
{
    if (!response)
    {
        SendClientMessage(playerid, -1, "Has omitido de la pregunta "COL_RED"#6.");
    }

    switch (listitem)
    {
        case 0: Question(playerid, 7, 0);
        case 1: Question(playerid, 7, 0);
        case 2: Question(playerid, 7, 0);
    }
}