#include "setup.h"
#include "stivale2/stivale2.h"
#include "stivale2/stivale2_tags.h"
#include "gdt/gdt.h"

void pre_setup(struct stivale2_struct* stivale2_struct)
{
    InitializeTags(stivale2_struct);
    //tty_init();

    GDTDescriptor gdtDescriptor;

    gdtDescriptor.size = sizeof(GDT) - 1;
    gdtDescriptor.offset = (uint64_t)&DefaultGDT;

    loadGDT(&gdtDescriptor);
}