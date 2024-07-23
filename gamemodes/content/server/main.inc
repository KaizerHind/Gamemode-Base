main() {   
    print("========================================");
    print("|*- index.pwn Cargado correctamente.   |");
    print("========================================");
    print("|*- Credits:                           |");
    print("========================================");
    print("|*- KaizerHind - Developer.            |");
    print("|*- VAAM - Developer.                  |");
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