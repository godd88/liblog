#include "liblog.h"

#ifdef LOG_MOD_ID
#undef LOG_MOD_ID
#define LOG_MOD_ID LOG_MOD_TEST1
#else
#define LOG_MOD_ID LOG_MOD_TEST1
#endif

void example_mod1() {
    Log_Init("mod1.log", LOG_MOD_TEST1, LOG_LEVEL_WARN, 1);

    log_info("hello-info %s\n", "good info");
    log_warn("hello-warn pi = %f\n", 3.14);
    log_error("hello-error %d\n", 999);
}
