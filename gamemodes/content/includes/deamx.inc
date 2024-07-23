#include <YSI_Coding\y_hooks>

AntiDescompiler()
{
    new antiDescompiler[][] =
    {
        "Unarmed (Fist)",
        "Brass K"
    };

    #pragma unused antiDescompiler
}

hook OnGamemodeInit()
{
    AntiDescompiler();
    return 1;
}
