forward PlayerIngreso(playerid); public PlayerIngreso(playerid) 
{
    cache_get_value_int(0, "Skin", PlayerData[playerid][jSkin]);
    cache_get_value_int(0, "Gender", PlayerData[playerid][jGender]);
    cache_get_value_int(0, "Score", PlayerData[playerid][jScore]);
    cache_get_value_float(0, "Health", PlayerData[playerid][jHealth]);
    cache_get_value_float(0, "Armour", PlayerData[playerid][jArmour]);
    cache_get_value_int(0, "Died", PlayerData[playerid][jScore]);
    cache_get_value_name(0, "Country", PlayerData[playerid][jCountry], 64);
    cache_get_value_float(0, "PosX", PlayerData[playerid][jPosX]);
    cache_get_value_float(0, "PosY", PlayerData[playerid][jPosY]);
    cache_get_value_float(0, "PosZ", PlayerData[playerid][jPosZ]);
    cache_get_value_float(0, "PosA", PlayerData[playerid][jPosA]);

    SetPlayerScore(playerid, PlayerData[playerid][jScore]);
    SetPlayerHealth(playerid, PlayerData[playerid][jHealth]);
    SetPlayerArmour(playerid, PlayerData[playerid][jArmour]);

    AccountLoaded(playerid);
    return 1;
}

forward AccountLoaded(playerid); public AccountLoaded(playerid){
    TogglePlayerSpectating(playerid, false);

    format(PlayerData[playerid][jName], 25, "%s", PlayerName(playerid));
	
    SetSpawnInfo(playerid, 0, PlayerData[playerid][jSkin], PlayerData[playerid][jPosX], PlayerData[playerid][jPosY], PlayerData[playerid][jPosZ], PlayerData[playerid][jPosA], 0, 0, 0, 0, 0, 0);
    StopAudioStreamForPlayer(playerid);
    SetPlayerColor(playerid, HCOL_WHITE);
	
    SpawnPlayer(playerid);
    SetPVarInt(playerid, "Logueado", 1);
    return 1;
}

forward LoadAccountID(playerid); public LoadAccountID(playerid) {PlayerData[playerid][ID] = cache_insert_id(); return 1;}

forward FinishedIntro(playerid); public FinishedIntro(playerid)
{
	TogglePlayerSpectating(playerid, false);
	SendClientMessage(playerid,-1,"- "COL_WHITE"!Felicidades; Bienvenido a "SERVER_NAME""COL_WHITE", disfruta tu estancia!");
	SetPVarInt(playerid, "Logueado", 1);

	SetPlayerScore(playerid, PlayerData[playerid][jScore] = 5);
	SetPlayerSkin(playerid, PlayerData[playerid][jSkin]);
    
    PlayerData[playerid][jPosX] = 1397.3853; PlayerData[playerid][jPosY] = -1577.9474; PlayerData[playerid][jPosZ] = 14.4706;
	SetSpawnInfo(playerid, 0, PlayerData[playerid][jSkin], 1397.3853, -1577.9474, 14.4706, 0.0, 0, 0, 0, 0, 0, 0);
    
    StopAudioStreamForPlayer(playerid);
    SetPlayerColor(playerid, HCOL_WHITE);
    ClearAnimations(playerid);

	SpawnPlayer(playerid);

	/* Discord: discord.inc */
	format(DiscordLog, sizeof(DiscordLog), "(( `%s` ha culminado su Registro y ha spawneado exitosamente. **[Part 3/3]** ))",  PlayerName(playerid));
	ConvertDiscordText(DiscordLog),
	SendRegisterEmbedMessage(DCHANNEL_LOG, DiscordLog);
	return 1;
}

stock SavePlayer(playerid) {

    GetPlayerHealth(playerid, PlayerData[playerid][jHealth]);
    GetPlayerArmour(playerid, PlayerData[playerid][jArmour]);
    GetPlayerScore(PlayerData[playerid][jScore]);
    GetPlayerPos(playerid, PlayerData[playerid][jPosX], PlayerData[playerid][jPosY], PlayerData[playerid][jPosZ]);
    GetPlayerFacingAngle(playerid, PlayerData[playerid][jPosA]);

    ReturnDate();

    mysql_format(DB, global_str, sizeof(global_str), "UPDATE users SET Score = '%d', Health = '%f', Armour = '%f', Died = '%d', Skin = '%d', Country = '%e', Acc_Last_Session = '%s', PosX = %f, PosY = %f, PosZ = %f, PosA = %f  WHERE ID = '%d' LIMIT 1",
        PlayerData[playerid][jScore],
        PlayerData[playerid][jHealth],
        PlayerData[playerid][jArmour],
        PlayerData[playerid][jHasDied],
        GetPlayerSkin(playerid),
        PlayerData[playerid][jCountry],
        ReturnDate(),
        PlayerData[playerid][jPosX],
        PlayerData[playerid][jPosY],
        PlayerData[playerid][jPosZ],
        PlayerData[playerid][jPosA],
        PlayerData[playerid][ID]
    );
    mysql_tquery(DB, global_str);
    return 1;
}