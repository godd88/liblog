#include "liblog.h"

static e_log_mod_id LOG_MOD_ID = LOG_MOD_TEST2;

void example_mod2() {
    Log_Init("mod2.log", LOG_MOD_TEST2, LOG_LEVEL_INFO);

    log_info("hello-info %s\n", "good info");
    log_warn("hello-warn pi = %f\n", 3.14);
    log_error("hello-error %d\n", 999);
}
