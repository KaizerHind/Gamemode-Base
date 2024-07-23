IsPlayerADM(playerid, level)
{
	new text[39];
	if (GetPlayerAdmin(playerid, level) == 0)
	{
		switch(level)
		{
			case rank_User: text = "Usuario";
			case rank_Helper: text = "Ayudante";
			case rank_MOD1: text = "Moderador I";
			case rank_MOD2: text = "Moderador II";
			case rank_OP1: text = "Operador I";
			case rank_OP2: text = "Operador II";
			case rank_GAMEOP: text = "Game Operator";
			case rank_ADMIN: text = "Administrador";
			case rank_OWNER: text = "Coordinador";
		}
		return 1;
	}
	return 0;
}

GetPlayerAdmin(playerid, nivel)
{
	if (!IsPlayerConnected(playerid)) return 0;
	if (nivel > 9)
	{
		if (!strcmp(PlayerData[playerid][jName], "Kaizer_Hind", true)) { return 1; }
	}
	else
	{
		if (!strcmp(PlayerData[playerid][jName], "Kaizer_Hind", true)) { return 1; }
		if (PlayerData[playerid][jAdminLevel] >= nivel) return 1;
	}
	return 0;
}

GetPlayerAdminName(playerid)
{
	new text[39];
	switch (PlayerData[playerid][jAdminLevel])
	{
		case rank_User: text = "Usuario";
		case rank_Helper: text = "Ayudante";
		case rank_MOD1: text = "Moderador I";
		case rank_MOD2: text = "Moderador II";
		case rank_OP1: text = "Operador I";
		case rank_OP2: text = "Operador II";
		case rank_GAMEOP: text = "Game Operator";
		case rank_ADMIN: text = "Administrador";
		case rank_OWNER: text = "Coordinador";
	}
	return text;
}