public OnPlayerSpawn(playerid)
{
	if (GetPVarInt(playerid, "Logueado"))
	{
		if(PlayerData[playerid][jHasDied] == 0)
		{
			PlayerFreeze(playerid, 3);
			SetPlayerPos(playerid, PlayerData[playerid][jPosX], PlayerData[playerid][jPosY], PlayerData[playerid][jPosZ]);
			return 1;
		}
		else if(PlayerData[playerid][jHasDied] == 1)
		{
			SetPlayerSkin(playerid, PlayerData[playerid][jSkin]);
			SetPlayerHealth(playerid, 90);
			SetPlayerInterior(playerid, 0);
			
			ac_SetPlayerPos(playerid, PlayerData[playerid][jPosX], PlayerData[playerid][jPosY], PlayerData[playerid][jPosZ]);
			ac_GetPlayerFacingAngle(playerid, PlayerData[playerid][jPosA]);
			SendClientMessage(playerid, HCOL_RED, "* Estás muriendo y perdiendo mucha sangre..\n"COL_WHITE"");
			SendClientMessage(playerid, HCOL_WHITE, "[Anonimo]: * Una persona te ha visto y ha llamado al 911. *");
			
			ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, 0, 0, 0, 1, 0);
		}
		else if(PlayerData[playerid][jHasDied] == 2)
		{			
			SetPlayerHealth(playerid, 45);
			ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, 0, 0, 0, 1, 0);
			SendClientMessage(playerid, -1, "Medico: Hey, al parecer ya has despertado, tuviste una fuerte contusion.");
			PlayerData[playerid][jHasDied] = 0;
		}
	}
	/* ############### DON TOUCH ############### */
	#if defined player_OnPlayerSpawn
		return player_OnPlayerSpawn(playerid);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn player_OnPlayerSpawn
#if defined player_OnPlayerSpawn
	forward player_OnPlayerSpawn(playerid);
#endif

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
		SetSpawnInfo(playerid, 0, PlayerData[playerid][jSkin], 1188.0311, -1321.3394, 13.3687, 0.0, 0, 0, 0, 0, 0, 0);
		PlayerData[playerid][jHasDied] = 2;
	}
    /* ############### DON TOUCH ############### */
    #if defined player_OnPlayerDeath
        return player_OnPlayerDeath(playerid, killerid, reason);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerDeath
    #undef OnPlayerDeath
#else
    #define _ALS_OnPlayerDeath
#endif

#define OnPlayerDeath player_OnPlayerDeath
#if defined player_OnPlayerDeath
    forward player_OnPlayerDeath(playerid, killerid, reason);
#endif

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    new bool:cancel = (clickedid == Text:INVALID_TEXT_DRAW);

    if(IsPlayerConnected(playerid))
    {
		if(cancel)
		{
			return SendClientMessage(playerid, HCOL_WHITE, "Has cancelado el Textdraw.");
		}
		/*else if(clickedid == Variable)
		{
			
		}*/
    }
	/* ############### DON TOUCH ############### */
	#if defined pregister_OnPlayerClickTextDraw
		return pregister_OnPlayerClickTextDraw(playerid, Text:clickedid);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerClickTextDraw
	#undef OnPlayerClickTextDraw
#else
	#define _ALS_OnPlayerClickTextDraw
#endif

#define OnPlayerClickTextDraw pregister_OnPlayerClickTextDraw
#if defined pregister_OnPlayerClickTextDraw
	forward pregister_OnPlayerClickTextDraw(playerid, Text:clickedid);
#endif