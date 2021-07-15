#pragma once
#include "stivale2.h"

struct Stivale2Tags
{
    struct stivale2_struct_tag_terminal* terminal_tag;
    struct stivale2_struct_tag_framebuffer* framebuffer_tag;
};


void InitializeTags(struct stivale2_struct* stivale2_struct);

struct Stivale2Tags* GetTags();