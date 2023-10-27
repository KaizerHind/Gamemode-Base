/*
# INFORMACION: 
# La mayoria de funciones aqui presentes son funciones estaticas, fijas y/o temporales, es un poco facil deducir que hace cada una.

# PlayerFreeze/PlayerUnfreeze = Congelamos o descongelamos al jugador por un lapso de tiempo.
# ClearChat = Realiza una limpieza del chat.
# ReasonKick & DialogKick = Timer de expulsion por nombre erroneo.
# CancelDialog & TimerKick = Expulsion por cancelar el Dialogo de registro u Otro.
# StartLoginCamera = Intro del Servidor.
# PreloadAnimLibs = Cargado de liberia de animaciones.
# ShowServerNameTD || CommandError = Textdraws del Servidor.
# Shortname || PlayerName || PlayerName_ = Chequeo y llamado del nombre del jugador.
# ValidateUppercase = Validacion del uso de _ En el nombre.
# InvalidCharacterName = Verificacion de carateres al usar un nombre invalido.
# ConvertDiscordText = Convierte el texto enviado a Discord con un formato normal sin caracteres extraños.
# PlayerIsDying = Verificacion y reduccion de vida.
# CleanVars = Limpieza de variables.
# WaitingAttemp = Tiempo de espera para usar un comando.
# ShowErrorNotify || HideErrorNotify || s_err_command || h_err_command = Textdraw Error de comando.
# ClearDiedAnims = Limpieza de funcion al morir y/o respawnear.
# AutoRol = Realiza un Rol automatico ya asignado.
# alm = Funcion de ayuda en verificacion/asignacion de ciertos datos.
# UserMessage = Envia un mensaje al otro usuario para notificar algo. (Puede usarse cuando recibes una transferencia de dinero, etc)
# ReturnDate || ReturnLastSession = Almacena la fecha de Registro y el otro Almacena la ultima vez que ingreso.
# GetMonth = Obtienes datos acerca del mes actual, el cual es almacenado en el ultimo ingreso al Servidor.
# OnQueryError = En caso de haber algun error de consulta al encender el Gamemode, sera mostrado en la consola.
# GetPlayerInRange = Cercania de jugadores.
# ProxDetector = Detector de mensajes.
*/

forward PlayerUnfreeze(playerid); public PlayerUnfreeze(playerid) return TogglePlayerControllable(playerid,true);

stock PlayerFreeze(playerid,seconds=0)
{
	if(!seconds) return TogglePlayerControllable(playerid,false);

	else if(seconds)
	{
		TogglePlayerControllable(playerid,false);
		SetTimerEx("PlayerUnfreeze",seconds*1000,false,"i",playerid);
	}
	return 1;
}

stock ClearChat(playerid,lineas){Loop(i,lineas,0) SendClientMessage(playerid,-1,""); return 1;}

forward ReasonKick(playerid); public ReasonKick(playerid) {ClearChat(playerid, 100); SendClientMessage(playerid, HCOL_WHITE, "Reinicia el "COL_SERVER"Launcher"COL_WHITE" e intenta con un nombre "COL_SERVER"Valido"COL_WHITE".");}
forward DialogKick(playerid); public DialogKick(playerid) return Kick(playerid);

forward CancelDialog(playerid); public CancelDialog(playerid) {ClearChat(playerid, 100); SendClientMessage(playerid, HCOL_SERVER, "Has Cancelado el Dialogo que tenias abierto; Te invitamos a re-ingresar nuevamente.");}

stock TimerKick(playerid){SetTimerEx("CancelDialog", 100, false, "i", playerid); SetTimerEx("DialogKick", 100, false, "i", playerid);return 1;}

stock StartLoginCamera(playerid)
{
    new RandMovement;
    RandMovement = random(3);
    TogglePlayerSpectating(playerid, true);
    PlayAudioStreamForPlayer(playerid, "https://cdn.discordapp.com/attachments/1070645473481859162/1135263686982893740/Melodic_Instrumental_ROCK_Metal_Arrangements_93.mp3", 0.0, 0.0, 0.0, 0.0, false);
    ClearChat(playerid, 100);

    switch(RandMovement)
    {
        case 0:
        {
            InterpolateCameraPos(playerid, 1821.641113, -1920.931152, 13.405388, 1821.379272, -1665.030517, 14.498521, 45000);
            InterpolateCameraLookAt(playerid, 1821.657226, -1915.932739, 13.531604, 1821.308349, -1660.035522, 14.711844, 22500);
        }
        case 1:
        {
            InterpolateCameraPos(playerid, 1565.513305, -1733.132446, 14.356844, 1578.185058, -1729.579711, 71.607223, 45000);
            InterpolateCameraLookAt(playerid, 1561.613769, -1736.157714, 15.157655, 1574.273071, -1732.688232, 71.423744, 45000);
        }
        case 2:
        {
            InterpolateCameraPos(playerid, 1308.438964, -1403.570190, 14.576297, 990.262329, -1416.168090, 56.591018, 45000);
            InterpolateCameraLookAt(playerid, 1303.439819, -1403.628540, 14.645874, 993.421386, -1413.238647, 54.053543, 22500);
        }
    }
    return 1;
}

forward PreloadAnimLibs(playerid);
public PreloadAnimLibs(playerid) {
  for(new i = 0; i < sizeof(AnimLibs); i++) {
      ApplyAnimation(playerid, AnimLibs[i], "null", 4.0, false, false, false, false, false, true);
  }
  return 1;
}

stock ShowServerNameTD(playerid){TextDrawShowForPlayer(playerid, TD_SERVERNAME[0]); TextDrawShowForPlayer(playerid, TD_SERVERNAME[1]); return 1;}

stock CommandError(playerid){TextDrawShowForPlayer(playerid, tdError[0]); TextDrawShowForPlayer(playerid, tdError[1]); TextDrawShowForPlayer(playerid, tdError[2]); return 1;}

stock Shortname(playerid){return IndividualName[playerid];}

ValidateUppercase(playerid, lastname[], nPosition)
{
	lastname[0] = toupper(lastname[0]);
	lastname[nPosition+1] = toupper(lastname[nPosition+1]);

	Loop(i, strlen(lastname), 1)
	{
	    if(i != (nPosition+1))
	    {
			lastname[i] = tolower(lastname[i]);
		}
	}

	alm(IndividualName[playerid], lastname);
	alm(IndividualPlayerName[playerid], lastname);

	IndividualPlayerName[playerid][nPosition] = ' ';

	#if FIX_SetPlayerName
	SetPlayerName(playerid,IndividualName[playerid]);
	#else
	SetPlayerName(playerid,"OTHER_NAME");
	SetPlayerName(playerid,IndividualName[playerid]);
	#endif

	return true;
}

stock InvalidCharacterName(str[])
{
	static const IlegalC[] =
	{
		'0','1','2','3','4',
		'5','6','7','8','9',
		'[',']','$','(',')',
		'.', '-'
	};

	Loop(i, strlen(str),0)
	{
		Loop(c, sizeof IlegalC, 0)
		{
		    if(str[i] == IlegalC[c]) return true;
		}
	}
	return false;
}

stock PlayerName(playerid){return IndividualPlayerName[playerid];}
stock PlayerName_(playerid){return IndividualPlayerName[playerid];}

stock ConvertDiscordText(string[])
{
    new 
        original[256] = {
        "á", "Á", "é", "É", "í", "Í", "ó", "Ó", "ú", "Ú", "´", "À", "Â", "Ä", "Æ", 
        "Ç", "È", "Ê", "Ë", "Ì", "Î", "Ï", "Ò", "Ô", "Ö", "Ù", "Û", "Ü", "ß", "à", "â", "ä", "æ", 
        "ç", "è", "ê", "ë", "ì", "î", "ï", "ò", "ô" "ö", "ù", "û", "ü" "Ñ", "ñ", "¿", "¡" "°"
    };
                                     
    new 
        fixed[256] = {
        "a", "A", "e", "E", "i", "I", "o", "I", "u", "U", "'", "A", "A", "A", "A",
        "C", "E", "E", "E", "I", "I", "I", "O", "O", "O", "U", "U", "U", "b", "a", "a", "a", "a",
        "c", "e", "e", "e", "i", "i", "i", "o", "o", "o", "u", "u", "u", "N", "n", " ", " ", " "
    };

    new 
        len = strlen(string)
    ;

    for (new i; i < len; i ++) 
    {
        for (new j; j < 256; j ++) 
        {
            if (string[i] == original[j]) 
            {
                string[i] = fixed[j];
                break;
            }
        }
    }

    return true;
}

forward PlayerIsDying(playerid);
public PlayerIsDying(playerid)
{
    foreach(new a: Player)
    {
        if(GetPVarInt(playerid,"Logueado") == 1) 
        {
            if(PlayerData[playerid][jHasDied] == 1)
            {
                new Float: Health;
                GetPlayerHealth(playerid, Health);
                SetPlayerHealth(playerid, Health-5);
                return 1;
            }
            else if(PlayerData[playerid][jHasDied] == 2)
            {			
			    SetTimerEx("ClearDiedAnims", 6000, false, "d", playerid);
            }
        }
    }
    return 1;
}

stock CleanVars(playerid){

    ClearAnimations(playerid);

    //PlayerData[playerid] = ResetVars;

    PlayerData[playerid][jSkin] = 0;
    PlayerData[playerid][jGender] = 0;
    PlayerData[playerid][jAge] = 0;
    PlayerData[playerid][jScore] = 0;
    PlayerData[playerid][jHealth] = 0;
    PlayerData[playerid][jArmour] = 0;
    PlayerData[playerid][jHasDied] = 0;
    alm(PlayerData[playerid][jCountry], "none");

    PlayerData[playerid][jPosX] = 0;
    PlayerData[playerid][jPosY] = 0;
    PlayerData[playerid][jPosZ] = 0;
    PlayerData[playerid][jPosA] = 0;

    PlayerData[playerid][jAccent] = 0;

    alm(PlayerData[playerid][jLastConec], "none");
    PlayerMuted[playerid] = 0;

    return 1;
}

forward WaitingAttemp(playerid); public WaitingAttemp(playerid){AttemptAction[playerid] = 0;}

forward s_err_command(playerid); public s_err_command(playerid) { ShowErrorNotify(playerid); PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0); }
forward h_err_command(playerid); public h_err_command(playerid) { HideErrorNotify(playerid); }

stock ShowErrorNotify(playerid)
{
   TextDrawShowForPlayer(playerid,tdError[0]);
   TextDrawShowForPlayer(playerid,tdError[1]);
   TextDrawShowForPlayer(playerid,tdError[2]);
}

stock HideErrorNotify(playerid)
{
   TextDrawHideForPlayer(playerid, tdError[0]);
   TextDrawHideForPlayer(playerid, tdError[1]);
   TextDrawHideForPlayer(playerid, tdError[2]);
}

forward ClearDiedAnims(playerid); public ClearDiedAnims(playerid) { ClearAnimations(playerid, true); PlayerData[playerid][jHasDied] = 0;}

stock AutoRol(playerid, rol[])
{
	new string[250];
	format(string, sizeof(string), "* %s %s *", PlayerName(playerid), rol);
	ProxDetector(20.0, playerid, string, HCOL_ME, HCOL_ME, HCOL_ME, HCOL_ME, HCOL_ME);
	return 1;
}

stock alm(string[],string2[]){strmid(string,string2,0,strlen(string2),strlen(string2)+1); return 1;}

stock UserMessage(playerID, color, message[], { _, Float, Text3D, Menu, Text, DB, DBResult, bool, File, hex, bit, bit_byte, Bit }:...)
{
	if (playerID == INVALID_PLAYER_ID)
	{
		return 0;
	}

	new targetString[256];
	new length = strlen(message);
	new argumentIndex = 2;
	for (new character = 0; character < length; character++)
	{
		new isFormatChar;
		if (message[character] == '%')
		{
			if (character + 1 < length)			{
				switch (message[character + 1])
				{
					case '%':
					{
						strcat(targetString, "%");
						isFormatChar = true;
					}
					case 'c':
					{
						argumentIndex++;
						format(targetString, sizeof(targetString), "%s%c", targetString, getarg(argumentIndex));
						isFormatChar = true;
					}
					case 'd':
					{
						argumentIndex++;
						format(targetString, sizeof(targetString), "%s%d", targetString, getarg(argumentIndex));
						isFormatChar = true;
					}
					case 'f':
					{
						argumentIndex++;
						format(targetString, sizeof(targetString), "%s%f", targetString, getarg(argumentIndex));
						isFormatChar = true;
					}
					case 's':
					{
						argumentIndex++;
						new string[256];
						GetStArg(argumentIndex, string);
						strcat(targetString, string);
						isFormatChar = true;
					}
				}
			}
		}
		if (isFormatChar)
		{
			character++;
		}
		else
		{
			format(targetString, sizeof(targetString), "%s%c", targetString, message[character]);
		}
	}
	SendClientMessage(playerID, color, targetString);
	return 1;
}

ReturnDate()
{
	static date[36];

	getdate(date[2], date[1], date[0]);
	gettime(date[3], date[4], date[5]);

	format(date, sizeof(date), "%02d-%02d-%d / %02d:%02d", date[0], date[1], date[2], date[3], date[4]);
	return date;
}

ReturnLastSession()
{
    new Ano, Mes, Dia, Hora, Minutos, Segundos, gformat[256];
    getdate(Ano, Mes, Dia);
    gettime(Hora, Minutos, Segundos);
    if (Hora >= 12) format(gformat, sizeof gformat, "%02d:%02d:%02d PM - %s %02d del %02d", (Hora == 12) ? (12) : (Hora - 12), Minutos, Segundos, GetMonth(Mes), Dia, Ano);
    else if (Hora < 12) format(gformat, sizeof gformat, "%02d:%02d:%02d AM - %s %02d del %02d", (Hora == 0) ? (12) : (Hora), Minutos, Segundos, GetMonth(Mes), Dia, Ano);
    return gformat;
}

GetMonth(Month)
{
    new MonthStr[15];
    switch(Month)
    {
        case 1:  MonthStr = "Enero";
        case 2:  MonthStr = "Febrero";
        case 3:  MonthStr = "Marzo";
        case 4:  MonthStr = "Abril";
        case 5:  MonthStr = "Mayo";
        case 6:  MonthStr = "Junio";
        case 7:  MonthStr = "Julio";
        case 8:  MonthStr = "Agosto";
        case 9:  MonthStr = "Septiembre";
        case 10: MonthStr = "Octubre";
        case 11: MonthStr = "Noviembre";
        case 12: MonthStr = "Diciembre";
    }
    return MonthStr;
}

public OnQueryError(errorid, const error[], const callback[], const query[], MySQL:handle)
{
    printf("ERROR SQL: Query: %s, callback: %s, error: %s",query,callback,error);
    return 1;
}

//Cercanía de jugadores
forward GetPlayerInRange(Float:radi, playerid, targetid);
public GetPlayerInRange(Float:radi, playerid, targetid)
{
	new Float:posx, Float:posy, Float:posz;
	new Float:oldposx, Float:oldposy, Float:oldposz;
	new Float:tempposx, Float:tempposy, Float:tempposz;
	GetPlayerPos(playerid, oldposx, oldposy, oldposz);
	GetPlayerPos(targetid, posx, posy, posz);
	tempposx = (oldposx -posx);
	tempposy = (oldposy -posy);
	tempposz = (oldposz -posz);
	if(((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
	{
	    return 1;
	}
	return 0;
}

//https://sampforum.blast.hk/showthread.php?tid=80850&pid=307442#pid307442
forward ProxDetector(Float:radi, playerid, str[], col1, col2, col3, col4, col5); public ProxDetector(Float:radi, playerid, str[],col1,col2,col3,col4,col5)
{
    if(IsPlayerConnected(playerid))
    {
        new Float:posx, Float:posy, Float:posz;
        new Float:oldposx, Float:oldposy, Float:oldposz;
        new Float:tempposx, Float:tempposy, Float:tempposz;
        GetPlayerPos(playerid, oldposx, oldposy, oldposz);
        for(new i = 0; i < MAX_PLAYERS; i++)
        {
            if(IsPlayerConnected(i))
            {

                GetPlayerPos(i, posx, posy, posz);
                tempposx = (oldposx -posx);
                tempposy = (oldposy -posy);
                tempposz = (oldposz -posz);
                if (((tempposx < radi/16) && (tempposx > -radi/16)) && ((tempposy < radi/16) && (tempposy > -radi/16)) && ((tempposz < radi/16) && (tempposz > -radi/16)))
                {
                    SendClientMessage(i, col1, str);
                }
                else if (((tempposx < radi/8) && (tempposx > -radi/8)) && ((tempposy < radi/8) && (tempposy > -radi/8)) && ((tempposz < radi/8) && (tempposz > -radi/8)))
                {
                    SendClientMessage(i, col2, str);
                }
                else if (((tempposx < radi/4) && (tempposx > -radi/4)) && ((tempposy < radi/4) && (tempposy > -radi/4)) && ((tempposz < radi/4) && (tempposz > -radi/4)))
                {
                    SendClientMessage(i, col3, str);
                }
                else if (((tempposx < radi/2) && (tempposx > -radi/2)) && ((tempposy < radi/2) && (tempposy > -radi/2)) && ((tempposz < radi/2) && (tempposz > -radi/2)))
                {
                    SendClientMessage(i, col4, str);
                }
                else if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
                {
                    SendClientMessage(i, col5, str);
                }
            }
        }
    }
    return 1;
}