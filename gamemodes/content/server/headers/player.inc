#define MAX_NPC (0)

#undef MAX_PLAYERS
#define MAX_PLAYERS (50)

#undef MAX_VEHICLES
#define MAX_VEHICLES (1000)


enum
{
    rank_User,
    rank_Helper,
    rank_MOD1,
    rank_MOD2,
    rank_OP1,
    rank_OP2,
    rank_GAMEOP,
    rank_ADMIN,
    rank_OWNER
}

enum jInfo //Info about of Player
{
    ID,
    jName[25],
    jPass[64 + 1],
    TempHash[64 + 1],
    
    jSkin,
    jGender,
    jAge,
    jScore,
    jMoney,
    Float:jHealth,
    Float:jArmour,
    jHasDied,
    jCountry[64],
    jAdminLevel,
 	
    jInterior,
    jVirtualWorld,
    Float:jPosX,
 	Float:jPosY,
 	Float:jPosZ,
    Float:jPosA,
    
    jAccent,
	SHAKE_OFFER,
	SHAKE_OFFER_TYPE,
	
	jLastConec[256]
}

new PlayerData[MAX_PLAYERS][jInfo];

new	
	MySQL:DB,
	//Check if and Change the name to Roleplay (_)
    IndividualName[MAX_PLAYERS][MAX_PLAYER_NAME], 
	IndividualPlayerName[MAX_PLAYERS][MAX_PLAYER_NAME],
	//Chechk if Player are Muted
    PlayerMuted[MAX_PLAYERS],
	// Wait Time Command
    AttemptAction[MAX_PLAYERS]
    ;
