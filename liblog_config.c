#include "liblog_config.h"

/****************************************************/
/****************** 修改配置的地方 *******************/
logg_Mod_Setting_t g_Mod_Setting[LOG_MOD_MAX] =
{
    [LOG_MOD_RESERVE] = {.name = "mod_reserve"},
    [LOG_MOD_TEST1]   = {.name = "mod_test_1"},
    [LOG_MOD_TEST2]   = {.name = "mod_test_2"},
    [LOG_MOD_MAIN]   = {.name = "mod_main"},
};
/* xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx */
/* xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx */
