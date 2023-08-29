/*
# REMEMBER TO ADD IN SERVER.CFG AND IN './content/discordconnector.inc' THE ID  #
# OF YOUR LOGS CHANNEL, OTHERWISE YOU MAY PRESENT SOME PROBLEMS WHEN COMPILING. #
*/

#define SSCANF_NO_NICE_FEATURES

/* ==# Native Includes #== */
#include    "a_samp"
#define     FIX_OnRconCommand 1
#define     FIX_OnClientCheckResponse 1
#include	"fixes"
#include    "a_mysql"
#include    "YSI_Data\y_iterate"
#include    "streamer"
#include    "sscanf2"
#include    "zcmd"

/* ==# Mini Funcs Modules [not very important] #== */
#include    "content/includes/discordconnector"
#include    "content/deamx"

/* ==# Vars Modules #== */
#include	"content/server/cColors"
#include	"content/server/mVars_"

/* ==# Funcs Modules #== */
#include    "content/includes/dialogs"
#define     DEBUG
#include    "nex-ac_es.lang"
#include    "nex-ac"
#include	"content/systems/pregister"
#include    "content/systems/discord"
#include    "content/systems/roltest"
#include    "content/systems/player"

/* ==# Other Funcs I #== */
#include	"content/designs/textdraws"
#include	"content/designs/maps"

/* ==# Commands #== */
#include    "content/cmds/p_commands"

/* ==# Other Funcs II #== */
#include	"content/server/sql"
#include	"content/server/utils"