#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include "liblog.h"


char* Lv2Str[] = {
    "debug",
    "info",
    "warn",
    "error"
};

e_log_level g_log_level = LOG_LEVEL_WARN;
e_log_level log_get_level() {
    return g_log_level;
}

int Log_Write(e_log_level level, e_log_mod_id mod_id,const char *subModule,const char* format, ...)
{
    char vbuff[MAX_LOG_BUF] = {0};
    char fbuff[MAX_LOG_BUF] = {0};

    va_list	argList;
    va_start(argList, format);
    int nLen=vsnprintf(vbuff, sizeof(vbuff), format, argList);
    va_end(argList);

    if(nLen <= 0)
    {
        return -1;
    }
    // return printf("%s-%s:%s%s", Lv2Str[level], g_Mod_Setting[mod_id].name, subModule, vbuff);
    snprintf(fbuff,
             MAX_LOG_BUF,
             "%s-%s:%s%s", Lv2Str[level], g_Mod_Setting[mod_id].name, subModule, vbuff
    );
    fwrite(fbuff, strlen(fbuff), 1, g_Mod_Setting[mod_id].fp);
    return 0;
}

int Log_Init(char* logfile, e_log_mod_id mod_id, e_log_level level) {
    g_log_level = level;
    FILE* fp = fopen(logfile, "a");
    if (NULL == fp) {
        return -1;
    }

    g_Mod_Setting[mod_id].fp = fp;

    return 0;
}
