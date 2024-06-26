#include "liblog.h"

#ifdef LOG_MOD_ID
#undef LOG_MOD_ID
#define LOG_MOD_ID LOG_MOD_TEST2
#else
#define LOG_MOD_ID LOG_MOD_TEST2
#endif

int example_mod2() {
    Log_Init("mod2.log", LOG_MOD_ID, LOG_LEVEL_ERROR, 0);

    log_info("hello-info %s\n", "good info");
    log_warn("hello-warn pi = %f\n", 3.14);
    log_error("hello-error %d\n", 999);
    return 1;
}
