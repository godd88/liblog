#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include "liblog.h"
#include <sys/time.h>
#include <time.h>


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
    char tbuff[MAX_LOG_BUF] = {0};
    char vbuff[MAX_LOG_BUF] = {0};
    char fbuff[MAX_LOG_BUF] = {0};

    if (g_Mod_Setting[mod_id].timestamp)
    {
        struct timeval tv;

        gettimeofday(&tv, NULL); // 获取1900到当前的秒数, 微秒数

        time_t curr_time = tv.tv_sec + 8*3600; // 转化成 东8区 可读的时间
        struct tm *tm_info = localtime(&curr_time);

        snprintf(tbuff, MAX_LOG_BUF, "[%04d/%02d/%02d %02d:%02d:%02d %u] ",
               tm_info->tm_year + 1900,
               tm_info->tm_mon + 1,
               tm_info->tm_mday,
               tm_info->tm_hour,
               tm_info->tm_min,
               tm_info->tm_sec,
               tv.tv_usec
        );
    }

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
             "%s%s-%s:%s%s", tbuff, Lv2Str[level], g_Mod_Setting[mod_id].name, subModule, vbuff
    );
    printf("%s", fbuff);
    fwrite(fbuff, strlen(fbuff), 1, g_Mod_Setting[mod_id].fp);
    return 0;
}

int Log_Init(char* logfile, e_log_mod_id mod_id, e_log_level level, char timestamp) {
    g_log_level = level;
    FILE* fp = fopen(logfile, "a");
    if (NULL == fp) {
        return -1;
    }

    g_Mod_Setting[mod_id].fp = fp;
    g_Mod_Setting[mod_id].timestamp = timestamp;

    return 0;
}
