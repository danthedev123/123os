#include <stddef.h>
#include "setup.h"

// The following will be our kernel's entry point.
extern "C" void _start(struct stivale2_struct *stivale2_struct) {
    
    pre_setup(stivale2_struct);
    
    // We're done, just hang...
    for (;;) {
        asm ("hlt");
    }
}