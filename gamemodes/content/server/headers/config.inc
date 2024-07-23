/* Macros */
#define Loop(%0,%1,%2)          for(new %0 = %2; %0 < %1; %0++)
#define DefaultCommand(%1,%2)   SendClientMessage(%1, HCOL_SERVER, ">> "#COL_WHITE"" %2)
#define ClientMessage(%1,%2)    SendClientMessage(%1, HCOL_WHITE, %2)
#define ServerAlert(%1,%2)      SendClientMessage(%1, -1, ""#COL_ERROR"[Servidor]: "#COL_WHITE"Invalid Error "#COL_E_CODE"" %2)
#define AllUserMessage(         UserMessage(INVALID_PLAYER_ID,
#define GetStArg(%1,%2)         for(new x = 0; getarg(%1,x) != '\0'; x++) %2[x] = getarg(%1,x)
#define INVALID (-1)

/* -= Settings Server.cfg =-*/
#define SERVER_NAME         "SAMP SERVER 0.3.7"
#define SERVER_MODE         "Interpretacion"
#define SERVER_MAP          "Los Santos"
#define SERVER_LANG         "Español/Spanish"
#define SERVER_RCON         ""
#define SERVER_GRAVITY      "0.008"

#define SERVER_DISCORD      "https://discord.gg/AfRennvxE9"
#define SERVER_CONTACT      "zaikmodding@gmail.com"

#define SERVER_PROJECT      "Auburn"

/* -= Settings Database =-*/
#define DB_HOSTNAME		"127.0.0.1"
#define DB_USERNAME		"root"
#define DB_DATABASE		"dbserver"
#define DB_PASSWORD		""

/* Default Messages */
#define mHeader             "\t"COL_SERVER""SERVER_NAME""
#define mError				""COL_ERROR"La contraseña ingresada no corresponde\na la registrada en la "#COL_WHITE"Base de datos.\n\nIntenta nuevamente."
/*======================================================================*/