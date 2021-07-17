#include "setup.h"
#include "stivale2/stivale2.h"
#include "stivale2/stivale2_tags.h"
#include "tty/tty.h"

void pre_setup(struct stivale2_struct* stivale2_struct)
{
    InitializeTags(stivale2_struct);
    tty_init();

    printk("Welcome to \x1b[1;31m1\x1b[1;36m2\x1b[1;32m3\x1b[0mOS!");
}