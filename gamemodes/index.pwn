#define SSCANF_NO_NICE_FEATURES

/* ==# Native Includes #== */
#include    "a_samp"
#define     FIX_OnRconCommand 1
#define     FIX_OnClientCheckResponse 1
#include	"fixes"
#include    "a_mysql"
#include    "YSI_Data\y_foreach"
#include    "YSI_Data\y_iterate"
#include    "streamer"
#include    "sscanf2"
#include    "PawnCMD"

/* ==# AntiDescompiler & Discord #== */
#include    "content/includes/discordconnector"
#include    "content/includes/deamx"

/* ==# Server Vars [Headers] #== */
#include	"content/server/headers/colors"
#include	"content/server/headers/player"
//#include	"content/server/headers/houses"
#include	"content/server/headers/strings"
#include    "content/server/headers/config"
#include    "content/server/main"
#include    "content/includes/dialogs"

/* ==# Server Systems [Callbacks] #== */
#define     DEBUG
#include    "nex-ac_es.lang"
#include    "nex-ac"
#include	"content/system/callbacks/connection"
#include	"content/system/callbacks/pregister"
#include    "content/system/callbacks/roltest"
#include    "content/system/callbacks/player"
//#include    "content/system/callbacks/houses"

/* ==# Design Server #== */
#include	"content/designs/textdraws"
#include	"content/designs/maps"

/* ==# Commands #== */
#include    "content/commands/a_cmds"
#include    "content/commands/p_cmds"
#include    "content/commands/f_cmds"
#include    "content/commands/headers/dialogcmd"

/* ==# Server/Systems Utils [functions] #== */
#include	"content/server/functions/sql"
//#include    "content/system/functions/houses"
//#include    "content/system/functions/dialoghouse"
#include	"content/server/functions/utils"
#include	"content/system/functions/admin"
#include    "content/server/functions/discord"