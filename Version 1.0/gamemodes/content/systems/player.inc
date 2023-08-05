public OnPlayerDeath(playerid, killerid, reason)
{
	Generado[playerid] = false;
	if(PlayerData[playerid][jHasDied] == 0)
	{
		GetPlayerPos(playerid, PosDiedX[playerid], PosDiedY[playerid], PosDiedZ[playerid]);
		SetSpawnInfo(playerid,0,PlayerData[playerid][jSkin],PosDiedX[playerid], PosDiedY[playerid], PosDiedZ[playerid],0,0,0,0,0,0,0);
		PlayerData[playerid][jHasDied] = 1;
		return 1;
	}
	else if(PlayerData[playerid][jHasDied] == 1)
	{
		SetSpawnInfo(playerid,0,PlayerData[playerid][jSkin],PosDiedX[playerid], PosDiedY[playerid], PosDiedZ[playerid],0,0,0,0,0,0,0);
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