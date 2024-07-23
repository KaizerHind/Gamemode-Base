#include <YSI_Coding\y_hooks>
#include <YSI_Data\y_foreach>

hook OnGameModeInit()
{

	/* ======== [ Connection DB ] ======== */
	new MySQLOpt:OP_ID = mysql_init_options();
	mysql_set_option(OP_ID, AUTO_RECONNECT, true);
	DB = mysql_connect(DB_HOSTNAME, DB_USERNAME, DB_PASSWORD, DB_DATABASE, OP_ID);
	
	if (mysql_errno(DB) == 0) {
		SendOnLineEmbedMessage(DCHANNEL_LOG, "La Conexion con la **Base de Datos** y **Discord** ha sido Exitosa - [MySQL]");
		print("La Conexion con la DB ha sido Exitosa - [MySQL]\n");
	} else {
		print("La Conexion con la DB ha Fallado - [MySQL]");
		SendRconCommand("exit");
	}
	return 1;
}

hook OnGameModeExit()
{
    foreach(new a: Player){SavePlayer(a);}
    mysql_close(DB);
	return 0;
}