public OnGameModeInit()
{
    /* # Intro de Ingreso # */

    
    /* ############### DON TOUCH ############### */
    #if defined Intro_OnGameModeInit
        return Intro_OnGameModeInit();
    #else
        return 1;
    #endif
}
#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif

#define OnGameModeInit Intro_OnGameModeInit
#if defined Intro_OnGameModeInit
    forward Intro_OnGameModeInit();
#endif