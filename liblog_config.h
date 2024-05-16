#ifndef __LIB_LOG_CONFIG_H__
#define __LIB_LOG_CONFIG_H__

#include <stdio.h>

typedef struct 
{
    char *name;
    char timestamp;
    FILE* fp;
} logg_Mod_Setting_t;


/****************************************************/
/****************** 修改配置的地方 *******************/
#define MAX_LOG_BUF         2048

typedef enum {
    LOG_MOD_RESERVE,
    LOG_MOD_TEST1,
    LOG_MOD_TEST2,
    LOG_MOD_MAIN,
    LOG_MOD_MAX
} e_log_mod_id;

extern logg_Mod_Setting_t g_Mod_Setting[LOG_MOD_MAX];  // 在 .c 中修改
/* xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx */
/* xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx */


#endif
