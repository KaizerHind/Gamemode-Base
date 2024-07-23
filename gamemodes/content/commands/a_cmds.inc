/*
..:::::..::........::........::..:::::::::........::..:::::..::
'##::::'##:'########:'##:::::::'########::'########:'########::
 ##:::: ##: ##.....:: ##::::::: ##.... ##: ##.....:: ##.... ##:
 ##:::: ##: ##::::::: ##::::::: ##:::: ##: ##::::::: ##:::: ##:
 #########: ######::: ##::::::: ########:: ######::: ########::
 ##.... ##: ##...:::: ##::::::: ##.....::: ##...:::: ##.. ##:::
 ##:::: ##: ##::::::: ##::::::: ##:::::::: ##::::::: ##::. ##::
 ##:::: ##: ########: ########: ##:::::::: ########: ##:::. ##:
..:::::..::........::........::..:::::::::........::..:::::..::
*/
flags:sethp(rank_Helper | rank_MOD1 | rank_MOD2 | rank_OP1 | rank_OP2 | rank_GAMEOP | rank_ADMIN | rank_OWNER)
cmd:sethp(playerid, params[]){
    new userid, health;
  	if(sscanf(params, "ui", userid, health)) return DefaultCommand(playerid, "/sethp id value");
    if (health > 100) return DefaultCommand(playerid, ""#COL_ERROR"[Servidor]:"#COL_WHITE" El limite de vida es entre 0 y 100."); 
	if(userid == INVALID_PLAYER_ID) return ServerAlert(playerid, "[01]");
	
    acc_SetPlayerHealth(userid, health);    
	UserMessage(userid, -1, ""COL_PINK"%s ha seteado tu vida en "COL_RED"%d hp"COL_WHITE".", PlayerName(playerid), health);
    format(global_str2, sizeof(global_str2), "Seteaste la vida de "COL_PINK"%s "COL_WHITE"en "COL_RED"%d "COL_WHITE"hp.", PlayerName(userid), health);
    SendClientMessage(playerid, -1, global_str2);
    return 1;
}
alias:sethp("sethealth", "darvida", "shp")

flags:setint(rank_Helper | rank_MOD1 | rank_MOD2 | rank_OP1 | rank_OP2 | rank_GAMEOP | rank_ADMIN | rank_OWNER)
cmd:setint(playerid, params[]){
    new userid, interiorpi, idvirtualworld;
  	if(sscanf(params, "uii", userid, interiorpi, idvirtualworld)) return DefaultCommand(playerid, "/setint id int vw");
    if (interiorpi < -1) return DefaultCommand(playerid, ""#COL_ERROR"[Servidor]:"#COL_WHITE" Invalid ID."); 
	if(userid == INVALID_PLAYER_ID) return ServerAlert(playerid, "[01]");
	
    SetPlayerInterior(userid, interiorpi);
    SetPlayerVirtualWorld(userid, idvirtualworld);
	UserMessage(userid, -1, "%s ha seteado tu interior y virtualworld en "COL_RED"%d/%d "COL_WHITE".", PlayerName(playerid), interiorpi, idvirtualworld);
    format(global_str2, sizeof(global_str2), "Seteaste el interior y virtualworld de %s "COL_WHITE"en "COL_RED"%d/%d "COL_WHITE".", PlayerName(userid), interiorpi, idvirtualworld);
    SendClientMessage(playerid, -1, global_str2);
    return 1;
}
alias:setint("setint", "sinterior", "sint")

/*
..:::::..:::.......:::........:::........::..:::::..::..:::::..::........::::.......:::..:::::..::........:::......:::
'##::::'##::'#######::'########::'########:'########:::::'###::::'########:::'#######::'########::'########::'######::
 ###::'###:'##.... ##: ##.... ##: ##.....:: ##.... ##:::'## ##::: ##.... ##:'##.... ##: ##.... ##: ##.....::'##... ##:
 ####'####: ##:::: ##: ##:::: ##: ##::::::: ##:::: ##::'##:. ##:: ##:::: ##: ##:::: ##: ##:::: ##: ##::::::: ##:::..::
 ## ### ##: ##:::: ##: ##:::: ##: ######::: ########::'##:::. ##: ##:::: ##: ##:::: ##: ########:: ######:::. ######::
 ##. #: ##: ##:::: ##: ##:::: ##: ##...:::: ##.. ##::: #########: ##:::: ##: ##:::: ##: ##.. ##::: ##...:::::..... ##:
 ##:.:: ##: ##:::: ##: ##:::: ##: ##::::::: ##::. ##:: ##.... ##: ##:::: ##: ##:::: ##: ##::. ##:: ##:::::::'##::: ##:
 ##:::: ##:. #######:: ########:: ########: ##:::. ##: ##:::: ##: ########::. #######:: ##:::. ##: ########:. ######::
..:::::..:::.......:::........:::........::..:::::..::..:::::..::........::::.......:::..:::::..::........:::......:::
*/

/*
:.......:::..:::::::::........::..:::::..::..:::::..::........::::.......:::..:::::..::........:::......:::
:'#######::'########::'########:'########:::::'###::::'########:::'#######::'########::'########::'######::
'##.... ##: ##.... ##: ##.....:: ##.... ##:::'## ##::: ##.... ##:'##.... ##: ##.... ##: ##.....::'##... ##:
 ##:::: ##: ##:::: ##: ##::::::: ##:::: ##::'##:. ##:: ##:::: ##: ##:::: ##: ##:::: ##: ##::::::: ##:::..::
 ##:::: ##: ########:: ######::: ########::'##:::. ##: ##:::: ##: ##:::: ##: ########:: ######:::. ######::
 ##:::: ##: ##.....::: ##...:::: ##.. ##::: #########: ##:::: ##: ##:::: ##: ##.. ##::: ##...:::::..... ##:
 ##:::: ##: ##:::::::: ##::::::: ##::. ##:: ##.... ##: ##:::: ##: ##:::: ##: ##::. ##:: ##:::::::'##::: ##:
. #######:: ##:::::::: ########: ##:::. ##: ##:::: ##: ########::. #######:: ##:::. ##: ########:. ######::
:.......:::..:::::::::........::..:::::..::..:::::..::........::::.......:::..:::::..::........:::......:::
*/

flags:givemoney(rank_OP1 | rank_OP2 | rank_GAMEOP | rank_ADMIN | rank_OWNER)
cmd:givemoney(playerid, params[]){
    new userid, money;
  	if(sscanf(params, "ui", userid, money)) return DefaultCommand(playerid, "/givemoney id value");
	if(userid == INVALID_PLAYER_ID) return ServerAlert(playerid, "[01]");
	
    acc_GivePlayerMoney(userid, money);
	UserMessage(userid, -1, ""COL_PINK"%s Te ha dado "COL_GREEN"$%d"COL_WHITE".", PlayerName(playerid), money);
    UserMessage(playerid, -1, ""COL_PINK"Le has dado a %s, "COL_GREEN"$%d"COL_WHITE".", PlayerName(userid), money);
    return 1;
}
alias:givemoney("dardinero", "ddinero", "dmoney")

flags:givescore(rank_OP1 | rank_OP2 | rank_GAMEOP | rank_ADMIN | rank_OWNER)
cmd:givescore(playerid, params[]){
    new userid, score;
  	if(sscanf(params, "ui", userid, score)) return DefaultCommand(playerid, "/givescore id value");
	if(userid == INVALID_PLAYER_ID) return ServerAlert(playerid, "[01]");
	
    SetPlayerScore(userid, score);
	UserMessage(userid, -1, ""COL_PINK"%s Te ha dado "COL_GREEN"$%d"COL_WHITE".", PlayerName(playerid), score);
    UserMessage(playerid, -1, ""COL_PINK"Le has dado a %s, "COL_GREEN"$%d"COL_WHITE".", PlayerName(userid), score);
    return 1;
}
alias:givescore("darscpre", "dscore", "ds")

/*
:......::::..:::::..::..:::::..::........::::::.......:::..:::::::::........::..:::::..::..:::::..:::::..::::::.......:::..:::::..::
:'######::::::'###::::'##::::'##:'########:::::'#######::'########::'########:'########:::::'###::::'########::'#######::'########::
'##... ##::::'## ##::: ###::'###: ##.....:::::'##.... ##: ##.... ##: ##.....:: ##.... ##:::'## ##:::... ##..::'##.... ##: ##.... ##:
 ##:::..::::'##:. ##:: ####'####: ##:::::::::: ##:::: ##: ##:::: ##: ##::::::: ##:::: ##::'##:. ##::::: ##:::: ##:::: ##: ##:::: ##:
 ##::'####:'##:::. ##: ## ### ##: ######:::::: ##:::: ##: ########:: ######::: ########::'##:::. ##:::: ##:::: ##:::: ##: ########::
 ##::: ##:: #########: ##. #: ##: ##...::::::: ##:::: ##: ##.....::: ##...:::: ##.. ##::: #########:::: ##:::: ##:::: ##: ##.. ##:::
 ##::: ##:: ##.... ##: ##:.:: ##: ##:::::::::: ##:::: ##: ##:::::::: ##::::::: ##::. ##:: ##.... ##:::: ##:::: ##:::: ##: ##::. ##::
. ######::: ##:::: ##: ##:::: ##: ########::::. #######:: ##:::::::: ########: ##:::. ##: ##:::: ##:::: ##::::. #######:: ##:::. ##:
:......::::..:::::..::..:::::..::........::::::.......:::..:::::::::........::..:::::..::..:::::..:::::..::::::.......:::..:::::..::
*/

/*
..:::::..::........:::..:::::..::....::..::::..::....:::......::::::..:::::..:::::..::..:::::..::........::::.......:::..:::::..::
:::'###::::'########::'##::::'##:'####:'##::: ##:'####::'######::'########:'########:::::'###::::'########:::'#######::'########::
::'## ##::: ##.... ##: ###::'###:. ##:: ###:: ##:. ##::'##... ##:... ##..:: ##.... ##:::'## ##::: ##.... ##:'##.... ##: ##.... ##:
:'##:. ##:: ##:::: ##: ####'####:: ##:: ####: ##:: ##:: ##:::..::::: ##:::: ##:::: ##::'##:. ##:: ##:::: ##: ##:::: ##: ##:::: ##:
'##:::. ##: ##:::: ##: ## ### ##:: ##:: ## ## ##:: ##::. ######::::: ##:::: ########::'##:::. ##: ##:::: ##: ##:::: ##: ########::
 #########: ##:::: ##: ##. #: ##:: ##:: ##. ####:: ##:::..... ##:::: ##:::: ##.. ##::: #########: ##:::: ##: ##:::: ##: ##.. ##:::
 ##.... ##: ##:::: ##: ##:.:: ##:: ##:: ##:. ###:: ##::'##::: ##:::: ##:::: ##::. ##:: ##.... ##: ##:::: ##: ##:::: ##: ##::. ##::
 ##:::: ##: ########:: ##:::: ##:'####: ##::. ##:'####:. ######::::: ##:::: ##:::. ##: ##:::: ##: ########::. #######:: ##:::. ##:
..:::::..::........:::..:::::..::....::..::::..::....:::......::::::..:::::..:::::..::..:::::..::........::::.......:::..:::::..::
*/

/*
:.......::::...::...:::..::::..::........::..:::::..::
:'#######::'##:::::'##:'##::: ##:'########:'########::
'##.... ##: ##:'##: ##: ###:: ##: ##.....:: ##.... ##:
 ##:::: ##: ##: ##: ##: ####: ##: ##::::::: ##:::: ##:
 ##:::: ##: ##: ##: ##: ## ## ##: ######::: ########::
 ##:::: ##: ##: ##: ##: ##. ####: ##...:::: ##.. ##:::
 ##:::: ##: ##: ##: ##: ##:. ###: ##::::::: ##::. ##::
. #######::. ###. ###:: ##::. ##: ########: ##:::. ##:
:.......::::...::...:::..::::..::........::..:::::..::                                    
*/
//flags:dadmin(rank_ADMIN | rank_OWNER)
CMD:dadmin(playerid, params[])
{
	new to_player, level;
	if (sscanf(params, "ud", to_player, level)) return DefaultCommand(playerid, "/dadmin <player_id> <0-8>");
	if(to_player == INVALID_PLAYER_ID) return ServerAlert(playerid, "[01]");
	if (level < 0 || level > 6) return DefaultCommand(playerid, "Solo existen 6 rangos administrativos.");
	if (IsPlayerADM(playerid, 7))
	{if (level < 0 || level > 6) return DefaultCommand(playerid, "Solo existen 6 rangos administrativos.");	} 
	else { if (level < 0 || level > 7) return DefaultCommand(playerid, "Solo existen 8 rangos administrativos."); }
	if (level == 0)
	{
		PlayerData[to_player][jAdminLevel] = 0;
		save_int_mysql("users", "TypeAdmin", PlayerData[to_player][ID], PlayerData[to_player][jAdminLevel]);	
        
        UserMessage(to_player, -1, "%s(%d) te ha expulsado de la administracion.", PlayerName(playerid), playerid);
        UserMessage(playerid, -1, "%s(%d) expulso de la administracion a %s(%d).", PlayerName(playerid), playerid, PlayerName(to_player), to_player);
    	return 1;
	}
	PlayerData[to_player][jAdminLevel] = level;
	save_int_mysql("users", "TypeAdmin", PlayerData[to_player][ID], PlayerData[to_player][jAdminLevel]);

    UserMessage(to_player, -1, "%s, tu rango administrativo fue atualizado a: %s(%d).", PlayerName(to_player), GetPlayerAdminName(to_player), level);
    UserMessage(playerid, -1, "El nuevo rango administrativo de %s(%d) ahora es %s(%d).", PlayerName(to_player), to_player, GetPlayerAdminName(to_player), level);
	return 1;
}

flags:getad(rank_Helper | rank_MOD1 | rank_MOD2 | rank_OP1 | rank_OP2 | rank_GAMEOP | rank_ADMIN | rank_OWNER)
cmd:getad(playerid) //Comando de prueba para comprobar tu rango.
{
    UserMessage(playerid, -1, "%s, tu rango administrativo es: %s.", PlayerName(playerid), GetPlayerAdminName(playerid));
    return 1;
}

CMD:aservice(playerid, params[])
{

    if(GetPVarInt(playerid, "godmod") == 0)
    {
        new Float:healths, Float:armours;
        //Old Health
        GetPlayerHealth(playerid,healths);
        SetPVarFloat(playerid, "health", healths);
        //Old Armour
        GetPlayerArmour(playerid,armours);
        SetPVarFloat(playerid, "armour", armours); SetPVarInt(playerid, "godmod", 1);
        SetPlayerHealth(playerid, 99999999); SetPlayerArmour(playerid, 99999999);
    }
    else
    {
        //Restore Health
        SetPlayerHealth(playerid, GetPVarFloat(playerid, "health"));
        //Restore Armour
        SetPlayerArmour(playerid, GetPVarFloat(playerid, "armour"));
        SetPVarInt(playerid, "godmod", 0);
    }
    return 1;
}alias:aservice("adminservice", "adservice", "adserv", "gmode", "gduty")