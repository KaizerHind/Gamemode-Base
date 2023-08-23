CMD:sp(playerid)
{
    SetPlayerPos(playerid, 1260.0173, -1161.1039, 42.1379);
    return 1;
}

CMD:curar(playerid)
{
    //if(GetPlayerMoney(playerid) < 1250) return SendClientMessage(playerid, -1, "Enfemera: !Al parecer no tienes el dinero suficiente!");
    if(PlayerData[playerid][jHasDied] == 0)
    {
        SendClientMessage(playerid, -1, "Medico: Al parecer no tienes enfermedades que curar, mucho menos estas muerto");
    }
    else
    {
        GivePlayerMoney(playerid, -3700);
        SetPlayerHealth(playerid, 100);
        SendClientMessage(playerid, -1, "Medico: ¡Enhorabuena; Todas tus enfermedades han sido curadas!");
    }
    return 1;
}