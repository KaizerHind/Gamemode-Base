/*
# INFORMATION:
# Most of the functions here are static, fixed and/or temporary functions, it's a bit easy to figure out what each one does.

# PlayerFreeze/PlayerUnfreeze = We freeze or unfreeze the player.
# ClearChat = Clear the chat.
# ReasonKick & DialogKick = Kick timer for wrong name.
# StartLoginCamera = Enter Server.
# PreloadAnimLibs = Loaded animation library.
# ShowServerNameTD || CommandError = Server Textdraws.
# shortname || PlayerName || PlayerName_ = Check and call player name.
# InvalidCharacterName = Invalid name check.
# ConvertDiscordText = Converts text sent to Discord to a normal format with no extraneous characters.
# PlayerIsDying = Check and life reduction.
# CleanVars = Clean variables.
# ReturnDate = Return date. (There is a bug to be fixed at login)0
# WaitingAttemp = Waiting time to use a command.
# ShowErrorNotify || HideErrorNotify || s_err_command || h_err_command = Textdraw Command error.
# ClearDiedAnims = Clear function on death and/or respawn.
# GetPlayerInRange = Nearness of players.
# ProxDetector = Message detector.
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

forward ReasonKick(playerid); public ReasonKick(playerid) {ClearChat(playerid, 100); SendClientMessage(playerid, HCOL_WHITE, "Restart the "COL_SERVER"Launcher"COL_WHITE" and try with a name "COL_SERVER"Valid"COL_WHITE".");}
forward DialogKick(playerid); public DialogKick(playerid) return Kick(playerid);

stock StartLoginCamera(playerid)
{
    new RandMovement;
    RandMovement = random(3);
    TogglePlayerSpectating(playerid, true);
    PlayAudioStreamForPlayer(playerid, INTRO_MUSIC, 0.0, 0.0, 0.0, 0.0, false);
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

stock ShowServerNameTD(playerid)
{
	TextDrawShowForPlayer(playerid, TD_SERVERNAME[0]);
	TextDrawShowForPlayer(playerid, TD_SERVERNAME[1]);
	return 1;
}

stock CommandError(playerid)
{
	TextDrawShowForPlayer(playerid, tdError[0]); TextDrawShowForPlayer(playerid, tdError[1]); TextDrawShowForPlayer(playerid, tdError[2]); return 1;
}

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

stock alm(string[],string2[]){strmid(string,string2,0,strlen(string2),strlen(string2)+1); return 1;}

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
        "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", 
        "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", 
        "�", "�", "�", "�", "�", "�", "�", "�", "�" "�", "�", "�", "�" "�", "�", "�", "�" "�"
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
        if(GetPVarInt(playerid,"Logged") == 1) 
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
	SetPVarInt(playerid, "Logged", 0);
    ClearAnimations(playerid);

    PlayerData[playerid][jHasDied] = false;
    PlayerData[playerid][jPosX] = 0;
    PlayerData[playerid][jPosY] = 0;
    PlayerData[playerid][jPosZ] = 0;
    PlayerData[playerid][jPosA] = 0;

    PlayerData[playerid][jAccent] = 0;

    PlayerMuted[playerid] = 0;
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

public OnQueryError(errorid, const error[], const callback[], const query[], MySQL:handle)
{
    printf("ERROR SQL: Query: %s, callback: %s, error: %s",query,callback,error);
    return 1;
}

//Cercan�a de jugadores
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