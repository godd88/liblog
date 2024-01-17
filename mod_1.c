#include "liblog.h"

static e_log_mod_id LOG_MOD_ID = LOG_MOD_TEST1;

void example_mod1() {
    Log_Init("mod1.log", LOG_MOD_TEST1, LOG_LEVEL_WARN);

    log_info("hello-info %s\n", "good info");
    log_warn("hello-warn pi = %f\n", 3.14);
    log_error("hello-error %d\n", 999);
}
