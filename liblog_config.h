#ifndef __LIB_LOG_CONFIG_H__
#define __LIB_LOG_CONFIG_H__

#include <stdio.h>

typedef enum {
    LOG_MOD_RESERVE,
    LOG_MOD_TEST1,
    LOG_MOD_TEST2,
    LOG_MOD_MAX
} e_log_mod_id;

typedef struct 
{
    char *name;
    char enabled;   // TODO
    FILE* fp;
} logg_Mod_Setting_t;


/****************************************************/
/****************** 修改配置的地方 *******************/
#define MAX_LOG_BUF         2048
#define LOG_MOD_ID          LOG_MOD_RESERVE;           // 需要在自己的模块中#undef 并重新#define

static logg_Mod_Setting_t g_Mod_Setting[LOG_MOD_MAX] =  // 用static 避免.h中定义变量重复定义
{
    [LOG_MOD_RESERVE] = {.name = "mod_reserve"},
    [LOG_MOD_TEST1]   = {.name = "mod_test_1"},
    [LOG_MOD_TEST2]   = {.name = "mod_test_2"},
};
/* xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx */
/* xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx */

#endif
