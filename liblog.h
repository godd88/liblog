#ifndef __LIB_LOG_H__
#define __LIB_LOG_H__

#include <string.h>
#include "liblog_config.h"

typedef enum {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR,
} e_log_level;

extern e_log_level log_get_level();
extern int Log_Write(e_log_level level, e_log_mod_id mod_id, const char* func, const char* format, ...);


/****************************************************/
/********************* 调用接口 **********************/
#define log_dbg(fmt, args...)      if (log_get_level()<=LOG_LEVEL_DEBUG) Log_Write(LOG_LEVEL_DEBUG, LOG_MOD_ID, __FUNCTION__, "[%s:%d]:" "\t" fmt, (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__), __LINE__, args);
#define log_info(fmt, args...)     if (log_get_level()<=LOG_LEVEL_INFO)  Log_Write(LOG_LEVEL_INFO,  LOG_MOD_ID, __FUNCTION__, "[%s:%d]:" "\t" fmt, (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__), __LINE__, args);
#define log_warn(fmt, args...)     if (log_get_level()<=LOG_LEVEL_WARN)  Log_Write(LOG_LEVEL_WARN,  LOG_MOD_ID, __FUNCTION__, "[%s:%d]:" "\t" fmt, (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__), __LINE__, args);
#define log_error(fmt, args...)    if (log_get_level()<=LOG_LEVEL_ERROR) Log_Write(LOG_LEVEL_ERROR, LOG_MOD_ID, __FUNCTION__, "[%s:%d]:" "\t" fmt, (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__), __LINE__, args);

// 不需要返回值的话也可自行替换局部变量rt定义一个新的 mac_rt，需要使用返回值亦可在func增加传出参数确定函数执行返回值
#define log_call_func(func) \
    do {\
        rt = func; \
        if (rt){ \
            log_error("%d = %s\n", rt, #func); \
        } else { \
            log_info("%d = %s\n", rt, #func); \
        } \
    } while(0);

extern int Log_Init(char* logfile, e_log_mod_id mod_id, e_log_level level, char timestamp);
/* xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx */
/* xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx */

#endif
