#include "liblog.h"


extern void example_mod1();
extern void example_mod2();

int main(int argc, char** argv) {
    example_mod1();
    example_mod2();

    return 0;
}
