/*
# Faccion: Medical Commands #
*/

CMD:salvar(playerid, params[])
{
	if(sscanf(params,"u", params[0])) return SendClientMessage(playerid, -1, ""COL_SERVER">> "COL_WHITE"/salvar [ID]");
	if(params[0] == INVALID_PLAYER_ID) return SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: "COL_WHITE"Invalid Error "COL_E_CODE"[01]");
    if(!GetPlayerInRange(1.5, playerid, params[0])) return SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: "COL_WHITE"Invalid Error "COL_E_CODE"[03]");
	if(IsPlayerInAnyVehicle(params[0])) return SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: "COL_WHITE"Invalid Error "COL_E_CODE"[04]");
	if(PlayerData[params[0]][jHasDied] == 0) return SendClientMessage(playerid, -1, ""COL_ERROR"[Servidor]: "COL_WHITE"Invalid Error "COL_E_CODE"[05]");

    format(global_str2, sizeof(global_str2), "%s aplicaria primeros auxilios basicos a %s.", PlayerName(params[0]));
	AutoRol(playerid, global_str2);
	UserMessage(params[0], HCOL_DO, "%s ha curado partes tus heridas.", PlayerName(playerid) );
	
	PlayerData[params[0]][jHasDied] = 0;
	return 1;
}