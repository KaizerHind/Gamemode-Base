/*
##    ## #### ####  ######  ####  #### #        #### ##    ## ####  ######
# #  # # #    #   #   ##   #     #   # #       #     # #  # # #   # #
#  ##  # ###  #   #   ##   #     ##### #       #     #  ##  # #   # ######    
#      # #    #   #   ##   #     #   # #       #     #      # #   #      #
#      # #### ####  ######  #### #   # #####    #### #      # ####  ######
*/

CMD:salvar(playerid, params[])
{
	static pj_injured;
	if(sscanf(params,"u", pj_injured)) return DefaultCommand(playerid, "/salvar id");
	if(pj_injured == INVALID_PLAYER_ID) return ServerAlert(playerid, "[01]");
	if(!GetPlayerInRange(1.5, playerid, pj_injured)) return ServerAlert(playerid, "[03]");
	if(IsPlayerInAnyVehicle(pj_injured)) return ServerAlert(playerid, "[04]");
	if(PlayerData[pj_injured][jHasDied] == 0) return ServerAlert(playerid, "[05]");

	UserMessage(pj_injured, HCOL_ME, "%s comienza a brindarte primeros auxilios.", PlayerName(playerid));	
	UserMessage(playerid, HCOL_ME, "%s estaria inspeccinando las heridas de %s.", PlayerName(playerid), PlayerName(pj_injured));

	format(global_str2, sizeof(global_str2), "%s estaria inspeccinando las heridas de %s.", PlayerName(playerid), PlayerName(pj_injured));
	SetPlayerChatBubble(playerid, global_str2, HCOL_ME, 60.0,5000);

	ApplyAnimation(playerid, "BOMBER", "BOM_Plant_Loop", 4.0, true, false, false, 1, 3000, true);

	PlayerData[pj_injured][jHasDied] = 0;
	TogglePlayerControllable(pj_injured, true);

	ApplyAnimation(playerid, "BOMBER", "BOM_Plant_Loop", 4.0, true, false, false, 1, 3000, true);
	ApplyAnimation(pj_injured, "CRACK", "crckidle3", 4.0, true, false, false, 1, 3000, true);
	return 1;
}

CMD:amb(playerid, params[])
{
	new passengertwo;
	if(GetPVarInt(playerid,"Logueado") == 0) return ServerAlert(playerid, "[00]");
	if(passengertwo == INVALID_PLAYER_ID) return ServerAlert(playerid, "[01]");
	if(!GetPlayerInRange(1.5, playerid, passengertwo)) return ServerAlert(playerid, "[03]");
	//if(!IsPlayerInAnyVehicle(passengertwo) || GetVehicleModel(GetPlayerVehicleID(passengertwo)) != 416) ServerAlert(playerid, "[04]");
	if(sscanf(params,"u", passengertwo)) return DefaultCommand(playerid, "/samb playerid");

	PutPlayerInVehicle(passengertwo, GetPlayerVehicleID(passengertwo), 3);
	format(global_str2, sizeof(global_str2), "%s ayuda a subir a %s en la ambulancia.", PlayerName(passengertwo)); AutoRol(playerid, global_str2);
	return 1;
}

CMD:samb(playerid, params[])
{
	new passengertwo;
	if(GetPVarInt(playerid,"Logueado") == 0) return ServerAlert(playerid, "[00]");
	if(passengertwo == INVALID_PLAYER_ID) return ServerAlert(playerid, "[01]");
	if(!GetPlayerInRange(1.5, playerid, passengertwo)) return ServerAlert(playerid, "[03]");
	if(!IsPlayerInAnyVehicle(passengertwo) || GetVehicleModel(GetPlayerVehicleID(passengertwo)) != 416) ServerAlert(playerid, "[04]");
	if(sscanf(params,"u", passengertwo)) return DefaultCommand(playerid, "/samb playerid");

	RemovePlayerFromVehicle(passengertwo);
	format(global_str2, sizeof(global_str2), "%s ayuda a %s a salir de la ambulancia.", PlayerName(passengertwo)); AutoRol(playerid, global_str2);
	return 1;
}


/*

#####	 ######  #     #######	 ###### #####    ####  ##    ## ####  ######
#    #	#      # #        ##	#       #       #      # #  # # #   # #
#####	#      # #        ##	#       #####   #      #  ##  # #   # ######    
#       #      # #        ##	#       #       #      #      # #   #      #
#        ######  ###### #######  ###### #####    ####  #      # ####  ######
*/



/*
 ####  ##    # ##    #    #### ##    ## ####  ######
#      # #   # # #   #   #     # #  # # #   # #
#      #  #  # #  #  #   #     #  ##  # #   # ######    
#      #   # # #   # #   #     #      # #   #      #
 ####  #     # #     #    #### #      # ####  ######
*/

