#include "YSI_Coding\y_hooks"

#if !defined isnull
	#define isnull(%1) \
		((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

#define Dialog:%0(%1) \
	forward dialog_%0(%1); public dialog_%0(%1)

#define Dialog_Show(%0,%1, \
	Open_Dialog(%0, #%1,

#define Dialog_Opened(%0) \
	(CallRemoteFunction("Dialog_IsOpened", "i", (%0)))

static
	s_DialogName[MAX_PLAYERS][32 char],
	s_DialogOpened[MAX_PLAYERS];

forward OnDialogPerformed(playerid, dialog[], response, success);

forward @dialog_format(); @dialog_format()
{
	format("", 0, "");
}

forward Dialog_IsOpened(playerid);
public Dialog_IsOpened(playerid)
{
	return (s_DialogOpened[playerid]);
}

stock Dialog_Close(playerid)
{
	s_DialogName[playerid]{0} = 0, 
	s_DialogOpened[playerid] = 0;

	return acc_ShowPlayerDialog(playerid, -1, DIALOG_STYLE_MSGBOX, " ", " ", " ", "");
}

stock Open_Dialog(playerid, const function[], style, caption[], info[], button1[], button2[])
{
	static
	    string[4096],
		args;

	if (!strlen(info)) return false;
	else if ((args = numargs()) > 7)
	{
	    while (--args >= 7)
		{
			#emit LCTRL 5
			#emit LOAD.alt args
			#emit SHL.C.alt 2
			#emit ADD.C 12
			#emit ADD
			#emit LOAD.I
			#emit PUSH.pri
		}
		#emit PUSH.S info
		#emit PUSH.C 4096
		#emit PUSH.C string

		#emit LOAD.S.pri 8
		#emit CONST.alt 16
		#emit SUB
		#emit PUSH.pri

		#emit SYSREQ.C format
		#emit LCTRL 5
		#emit SCTRL 4

		acc_ShowPlayerDialog(playerid, 32700, style, caption, string, button1, button2);
	}
	else acc_ShowPlayerDialog(playerid, 32700, style, caption, info, button1, button2);
	
	s_DialogOpened[playerid] = 1;

	//HidePlayerInfo(playerid),
	GameTextForPlayer(playerid, "_", 1000, 1);

	strpack(s_DialogName[playerid], function, 32 char);
	return true;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	CallRemoteFunction("SetPlayerCurrentDialog", "ii", playerid, dialogid);

   	static
		s_Public = cellmax;

	if (s_Public == cellmax) s_Public = funcidx("OnDialogPerformed");

	for (new i = 0, l = strlen(inputtext); i < l; i ++)
	{
	    if (inputtext[i] == '%') 
	    	inputtext[i] = '#';
	}

	if (dialogid == 32700 && strlen(s_DialogName[playerid]) > 0)
	{
		new
			string[40];

		strcat(string, "dialog_"), strcat(string, s_DialogName[playerid]);

		//Dialog_Close(playerid);

		if ((s_Public == -1) || (CallLocalFunction("OnDialogPerformed", "dsdd", playerid, string[7], response, funcidx(string) != -1)))
		{
	 		CallLocalFunction(string, "ddds", playerid, response, listitem, (!inputtext[0]) ? ("\1") : (inputtext));
		}
	}
	return 1;
}
