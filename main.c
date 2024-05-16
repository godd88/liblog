#include "liblog.h"


extern void example_mod1();
extern int example_mod2();

#define LOG_MOD_ID LOG_MOD_MAIN


int main(int argc, char** argv) {
    int rt = 0;
    Log_Init("main.log", LOG_MOD_ID, LOG_LEVEL_DEBUG, 1);

    example_mod1();
    log_call_func(example_mod2()); // 函数返回值传给 rt

    printf("rt = %d\n", rt);
    return rt;
}
