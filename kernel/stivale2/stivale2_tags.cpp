#include "stivale2_tags.h"
#include "stivale2_main.h"
#include "stivale2.h"
#include <stddef.h>

static struct Stivale2Tags tags;


void InitializeTags(struct stivale2_struct* stivale2_struct)
{
    tags.framebuffer_tag = (stivale2_struct_tag_framebuffer*)stivale2_get_tag(stivale2_struct, STIVALE2_STRUCT_TAG_FRAMEBUFFER_ID);
    tags.terminal_tag = (stivale2_struct_tag_terminal*)stivale2_get_tag(stivale2_struct, STIVALE2_STRUCT_TAG_TERMINAL_ID);
}

struct Stivale2Tags* GetTags()
{
    return &tags;
}
