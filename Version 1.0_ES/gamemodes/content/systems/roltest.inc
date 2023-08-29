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
            strcat(st_questions, "1. "COL_WHITE"Lo golpeo tambi�n hasta la muerte, si �l no sigue las normativas yo no tengo porque hacerlo tambi�n.\n", sizeof(st_questions));
            strcat(st_questions, "2. "COL_WHITE"Reporto v�a /re ID, al tratarse de un nivel bajo intentar�a detenerlo y aconsejarle.\n", sizeof(st_questions));            
            strcat(st_questions, "3. "COL_WHITE"Lo insulto mediante el /b, est� entorpeciendo mi rol.\n", sizeof(st_questions));
            Dialog_Show(playerid, DialogQuestion_0, DIALOG_STYLE_TABLIST_HEADERS, ""COL_SERVER"#1 � Un usuario nuevo comienza a golpearte sin motivo alguno; �Como actuarias?", st_questions, "Responder", "");
        }
        case 2:
        {
            new st_questions[500];
            strcat(st_questions, ""COL_SERVER""SERVER_NAME"\n", sizeof(st_questions));
            strcat(st_questions, "1. "COL_WHITE"Para alimentar al entorno que me rodea con: las acciones que va realizando mi personaje.\n", sizeof(st_questions));
            strcat(st_questions, "2. "COL_WHITE"Para describir las acciones que deseo que hagan el resto de los personajes.\n", sizeof(st_questions));
            strcat(st_questions, "3. "COL_WHITE"Para aclarar situaciones de interpretaci�n o describir el entorno que me rodea.", sizeof(st_questions));
            Dialog_Show(playerid, DialogQuestion_1, DIALOG_STYLE_TABLIST_HEADERS, ""COL_SERVER"#2 � �Para qu� se utiliza el famoso comando \"/do\" � \"/en\"?", st_questions, "Responder", "");
        }
        case 3:
        {
            new st_questions[500];
            strcat(st_questions, ""COL_SERVER""SERVER_NAME"\n", sizeof(st_questions));
            strcat(st_questions, "1. "COL_WHITE"Rolear las heridas al instante, es lo correcto en cuanto a interpretaci�n.\n", sizeof(st_questions));
            strcat(st_questions, "2. "COL_WHITE"Roleo las heridas una vez transcurrido el rol, debido a que mi personaje no siente los da�os al instante.\n", sizeof(st_questions));
            strcat(st_questions, "3. "COL_WHITE"Me da igual si muero, voy a respawnear de todas formas y podr� conseguir otra arma.", sizeof(st_questions));
            Dialog_Show(playerid, DialogQuestion_2, DIALOG_STYLE_TABLIST_HEADERS, ""COL_SERVER"#3 � Est�s en medio de un tiroteo, te disparan 2 veces hasta dejarte con 10 de vida.", st_questions, "Responder", "");
        }
        case 4:
        {
            new st_questions[500];
            strcat(st_questions, ""COL_SERVER""SERVER_NAME"\n", sizeof(st_questions));
            strcat(st_questions, "1. "COL_WHITE"Mal, ya qu� no estoy respetando el entorno del lugar en el que me encuentro en ese mismo instante.\n", sizeof(st_questions));
            strcat(st_questions, "2. "COL_WHITE"Bien, es mi arma y puedo hacer lo qu� quiera con ella. Si un policia dice lo contrario, lo baleo a c�mo de lugar.\n", sizeof(st_questions));
            strcat(st_questions, "3. "COL_WHITE"Ninguna de las anteriores.", sizeof(st_questions));
            Dialog_Show(playerid, DialogQuestion_3, DIALOG_STYLE_TABLIST_HEADERS, ""COL_SERVER"#4 � Obtienes de un arma, vas con ella por v�a publica c�mo si nada, esto est�:", st_questions, "Responder", "");
        }
        case 5:
        {
            new st_questions[500];
            strcat(st_questions, ""COL_SERVER""SERVER_NAME"\n", sizeof(st_questions));
            strcat(st_questions, "1. "COL_WHITE"Para reportar disgustos en mis experiencias dentro de "SERVER_PROJECT".\n", sizeof(st_questions));
            strcat(st_questions, "2. "COL_WHITE"Para reportar las falta de experiencia en rol de los otros usuarios.\n", sizeof(st_questions));
            strcat(st_questions, "3. "COL_WHITE"Para solicitar asistencia administrativa. O ayudarme con algo solucionable al instante.", sizeof(st_questions));
            Dialog_Show(playerid, DialogQuestion_4, DIALOG_STYLE_TABLIST_HEADERS, ""COL_SERVER"#5 � �Para qu� sirve el comando \"/reportar\"?", st_questions, "Responder", "");
        }
        case 6:
        {
            new st_questions[500];
            strcat(st_questions, ""COL_SERVER""SERVER_NAME"\n", sizeof(st_questions));
            strcat(st_questions, "1. "COL_WHITE"Ignoro sus faltas de rol. Sigo con lo que est�bamos haciendo. �Nulos los hay por doquier!\n", sizeof(st_questions));
            strcat(st_questions, "2. "COL_WHITE"Sigo nuestro rol mientras documento gr�ficamente. Una vez conclu�do el rol: lo reporto v�a foro.\n", sizeof(st_questions));
            strcat(st_questions, "3. "COL_WHITE"Autom�ticamente corto todo rol. Saco capturas de mi pantalla como evidencia y lo reporto en el foro.", sizeof(st_questions));
            Dialog_Show(playerid, DialogQuestion_5, DIALOG_STYLE_TABLIST_HEADERS, ""COL_SERVER"#6 � Un personaje con el que est�s roleando comienza a cometer faltas de rol, �qu� haces?", st_questions, "Resultados", "");
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
                format(DiscordLog, sizeof(DiscordLog), "(( `%s` comenzara a registrar su Cuenta en el Servidor. **[Part 2/3]**))", PlayerName(playerid));
                ConvertDiscordText(DiscordLog),
                SendRegisterEmbedMessage(DCHANNEL_LOG, DiscordLog);

                format(global_str, sizeof(global_str), ""COL_WHITE"Bienvenido a "COL_SERVER""SERVER_PROJECT" "COL_SERVER"%s"COL_WHITE"! Felicidades por aprobar el Examen de Rol.\nEsperamos te diviertas dentro de la Comunidad, no olvides respetar las Reglas\ny jugar de manera sana, cualquier falta puede conllevar a una sancion.\n\nSin nada mas que decir; Procedamos a tomar tus datos.\n\nIngresa una contrase�a para registrar tu cuenta.", PlayerName(playerid));
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

/* Plantilla:
0 = Respuesta buena. | Good Answer.
1 = Respuesta mala. | Bad Answer.

Example:
Question(playerid, X, 0); | Good Answer.
Question(playerid, X, 1); | Bad Answer.

Answers Questions: 2, 1-3, 2, 1, 2, 3.
*/

Dialog:DialogQuestion_0(playerid, response, listitem, inputtext[])
{
    if (!response)
    {
        SendClientMessage(playerid, -1, "Has omitido de la pregunta "COL_RED"#1.");
    }

    switch (listitem)
    {
        case 0: Question(playerid, 2, 1);
        case 1: Question(playerid, 2, 0);
        case 2: Question(playerid, 2, 1);
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
        case 1: Question(playerid, 3, 1);
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
        case 0: Question(playerid, 4, 1);
        case 1: Question(playerid, 4, 0);
        case 2: Question(playerid, 4, 1);
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
        case 1: Question(playerid, 5, 1);
        case 2: Question(playerid, 5, 1);
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
        case 0: Question(playerid, 6, 1);
        case 1: Question(playerid, 6, 0);
        case 2: Question(playerid, 6, 1);
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
        case 0: Question(playerid, 7, 1);
        case 1: Question(playerid, 7, 1);
        case 2: Question(playerid, 7, 0);
    }
}