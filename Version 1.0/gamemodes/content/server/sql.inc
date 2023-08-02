forward PlayerIngreso(playerid); public PlayerIngreso(playerid) 
{
    cache_get_value_int(0, "Ropa", PlayerData[playerid][jRopa]);
    cache_get_value_int(0, "Sexo", PlayerData[playerid][jSexo]);
    cache_get_value_int(0, "Score", PlayerData[playerid][jScore]);
    cache_get_value_float(0, "Salud", PlayerData[playerid][jHealth]);
    cache_get_value_float(0, "Armadura", PlayerData[playerid][jArmour]);
    cache_get_value_name(0, "Country", PlayerData[playerid][jCountry]);

    SetPlayerScore(playerid, PlayerData[playerid][jScore]);
    SetPlayerHealth(playerid, PlayerData[playerid][jHealth]);
    SetPlayerArmour(playerid, PlayerData[playerid][jArmour]);

    SetPVarInt(playerid, "Logueado", 1);
    AccountLoaded(playerid);
    return 1;
}

forward AccountLoaded(playerid); public AccountLoaded(playerid){
    TogglePlayerSpectating(playerid, false);

    format(PlayerData[playerid][jName], 25, "%s", PlayerName(playerid));
	SetSpawnInfo(playerid, 0, PlayerData[playerid][jRopa], 1397.3853, -1577.9474, 14.4706, 0.0, 0, 0, 0, 0, 0, 0);
    SetPlayerColor(playerid, HCOL_WHITE);
	SpawnPlayer(playerid);
    return 1;
}

forward LoadAccountID(playerid); public LoadAccountID(playerid) {PlayerData[playerid][ID] = cache_insert_id(); return 1;}

forward FinishedIntro(playerid); public FinishedIntro(playerid)
{
	TogglePlayerSpectating(playerid, false);
	SendClientMessage(playerid,-1,"- "COL_WHITE"!Felicidades; Bienvenido a "mHeader""COL_WHITE", disfruta tu estancia!");

	SetPVarInt(playerid, "Logueado", 1);

	SetPlayerScore(playerid, PlayerData[playerid][jScore] = 5);

	SetSpawnInfo(playerid, 0, PlayerData[playerid][jRopa], 1397.3853, -1577.9474, 14.4706, 0.0, 0, 0, 0, 0, 0, 0);
    SetPlayerColor(playerid, HCOL_WHITE);
	SpawnPlayer(playerid);
	
	/* Discord: discord.inc */
	format(gbl_log, sizeof(gbl_log), "(( `%s` ha culminado su Registro y ha spawneado exitosamente. **[Part 3/3]** ))",  PlayerName(playerid));
	ConvertDiscordText(gbl_log),
	SendRegisterEmbedMessage(DCHANNEL_LOG, gbl_log);
	return 1;
}

stock SavePlayer(playerid) {
    GetPlayerHealth(playerid, PlayerData[playerid][jHealth]);
    GetPlayerArmour(playerid, PlayerData[playerid][jArmour]);
    GetPlayerScore(PlayerData[playerid][jScore]);

    mysql_format(DB, global_str, sizeof(global_str), "UPDATE users SET Score = '%d', Salud = '%f', Armadura = '%f', Ropa = %d, Country = '%e' WHERE ID = '%d' LIMIT 1",
        PlayerData[playerid][jScore],
        PlayerData[playerid][jHealth],
        PlayerData[playerid][jArmour],
        GetPlayerSkin(playerid),
        PlayerData[playerid][jCountry],
        PlayerData[playerid][ID]
    );
    mysql_tquery(DB, global_str);
    return 1;
}