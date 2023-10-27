#define MAX_NPC (0)

#undef MAX_PLAYERS
#define MAX_PLAYERS (50)

#undef MAX_VEHICLES
#define MAX_VEHICLES (1000)

/*# Info about of Player #*/
enum jInfo 
{
    ID,
    jName[25],
    jPass[64 + 1],
    TempHash[64 + 1],

    jSkin,
    jGender,
    jAge,
    jScore,
    Float:jHealth,
    Float:jArmour,
    jHasDied,
    jCountry[64],

    Float:jPosX,
    Float:jPosY,
    Float:jPosZ,
    Float:jPosA,

    jAccent,

    jLastConec[256]
}

new PlayerData[MAX_PLAYERS][jInfo];

/* -= Mysql Vars and Others=- */
new	
    MySQL:DB,
    /* # Check and Change the name Roleplay (_)# */
    IndividualName[MAX_PLAYERS][MAX_PLAYER_NAME],
    IndividualPlayerName[MAX_PLAYERS][MAX_PLAYER_NAME],
    /* # Chechk if Player are Muted # */
    PlayerMuted[MAX_PLAYERS],
    /* # Wait Time Command */
    AttemptAction[MAX_PLAYERS]
    ;

//-= String Messages =-
new 
    st_InvalidName[400], st_Disconnect[200], DiscordLog[1024],
    st_FailTest[150], global_str[1024], global_str2[500]
    ;

//-=  Vars - WindowsScreen and Error Command =-
new Text:tdError[3], Text:TD_SERVERNAME[2];

//-= Discord Channel And RolTest Var =-
new DCC_Channel:ChannelBot, RolTestErrors[MAX_PLAYERS];

/*# Anim SAMP Library#*/
new const AnimLibs[][] = {
  "AIRPORT",      "ATTRACTORS",   "BAR",          "BASEBALL",     "BD_FIRE",
  "BEACH",        "BENCHPRESS",   "BF_INJECTION", "BIKE_DBZ",     "BIKED",
  "BIKEH",        "BIKELEAP",     "BIKES",        "BIKEV",        "BLOWJOBZ",
  "BMX",          "BOMBER",       "BOX",          "BSKTBALL",     "BUDDY",
  "BUS",          "CAMERA",       "CAR",          "CAR_CHAT",     "CARRY",
  "CASINO",       "CHAINSAW",     "CHOPPA",       "CLOTHES",      "COACH",
  "COLT45",       "COP_AMBIENT",  "COP_DVBYZ",    "CRACK",        "CRIB",
  "DAM_JUMP",     "DANCING",      "DEALER",       "DILDO",        "DODGE",
  "DOZER",        "DRIVEBYS",     "FAT",          "FIGHT_B",      "FIGHT_C",
  "FIGHT_D",      "FIGHT_E",      "FINALE",       "FINALE2",      "FLAME",
  "FLOWERS",      "FOOD",         "FREEWEIGHTS",  "GANGS",        "GFUNK",
  "GHANDS",       "GHETTO_DB",    "GOGGLES",      "GRAFFITI",     "GRAVEYARD",
  "GRENADE",      "GYMNASIUM",    "HAIRCUTS",     "HEIST9",       "INT_HOUSE",
  "INT_OFFICE",   "INT_SHOP",     "JST_BUISNESS", "KART",         "KISSING",
  "KNIFE",        "LAPDAN1",      "LAPDAN2",      "LAPDAN3",      "LOWRIDER",
  "MD_CHASE",     "MD_END",       "MEDIC",        "MISC",         "MTB",
  "MUSCULAR",     "NEVADA",       "ON_LOOKERS",   "OTB",          "PARACHUTE",
  "PARK",         "PAULNMAC",     "PED",          "PLAYER_DVBYS", "PLAYIDLES",
  "POLICE",       "POOL",         "POOR",         "PYTHON",       "QUAD",
  "QUAD_DBZ",     "RAPPING",      "RIFLE",        "RIOT",         "ROB_BANK",
  "ROCKET",       "RUNNINGMAN",   "RUSTLER",      "RYDER",        "SCRATCHING",
  "SEX",          "SHAMAL",       "SHOP",         "SHOTGUN",      "SILENCED",
  "SKATE",        "SMOKING",      "SNIPER",       "SNM",          "SPRAYCAN",
  "STRIP",        "SUNBATHE",     "SWAT",         "SWEET",        "SWIM",
  "SWORD",        "TANK",         "TATTOOS",      "TEC",          "TRAIN",
  "TRUCK",        "UZI",          "VAN",          "VENDING",      "VORTEX",
  "WAYFARER",     "WEAPONS",      "WOP",          "WUZI"
};

new const txtCountry[][] = {
    {"Los Santos"},
    {"BlueBerry"},
    {"Montgomery"},
    {"Palomino Creek"},
    {"Las Venturas"},
    {"Fort Cartson"},
    {"Bayside"},
    {"San Fierro"},
    {"Angel Pine"}
};


/*======================================================================*/

/* Macros */
#define Loop(%0,%1,%2)          for(new %0 = %2; %0 < %1; %0++)
#define AllUserMessage(         UserMessage(INVALID_PLAYER_ID,
#define GetStArg(%1,%2)         for(new x = 0; getarg(%1,x) != '\0'; x++) %2[x] = getarg(%1,x)

/* Configuracion Manual Server.cfg */
#define SERVER_NAME         "SERVER-NAME"
#define SERVER_MODE         "Interpretacion"
#define SERVER_MAP          "San Andreas"
#define SERVER_LANG         "Language"
#define SERVER_RCON         ""
#define SERVER_GRAVITY      "0.008"

/*# PawnCode Community #*/
#define SERVER_DISCORD      "https://discord.gg/RcmTvFPQZw"
#define SERVER_CONTACT      "zaikmodding@gmail.com"

#define SERVER_PROJECT      "Name"

/* Mensajes Predeterminados */
#define mHeader             "\t"COL_SERVER""SERVER_NAME""
#define mError				""COL_ERROR"La contrase�a ingresada no corresponde\na la registrada en la "#COL_WHITE"Base de datos.\n\nIntenta nuevamente."
/*======================================================================*/

main() {   
    print("========================================");
    print("|*- index.pwn Cargado correctamente.   |");
    print("========================================");
    print("|*- Credits:                           |");
    print("========================================");
    print("|*- KaizerHind - Developer.            |");
    print("|*- D13G0 - Doubts about MySql.        |");
    print("|*- Galasso - Hash password solution.  |");
    print("|*- r99t - Doubts about MySql.         |");
    print("|*- DeusExMachina - Solution SP/SD     |");
    print("========================================");
}

PlayerTemp(playerid){
    new name[24 + 1];
    GetPlayerName(playerid, name, MAX_PLAYER_NAME);
    return name;
}