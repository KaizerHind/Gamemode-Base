new //-= String Messages =-
    st_InvalidName[400], st_Disconnect[200], DiscordLog[1024],
    st_FailTest[150], global_str[1024], global_str2[500]
    ;

// WindowsScreen and Error Command =-
new Text:tdError[3], Text:TD_SERVERNAME[2];

// Discord Channel And RolTest Var
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

new const txtCountry[][] = { //Selection Character City
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