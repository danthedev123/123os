#include "tty.h"
#include <stddef.h>
#include "../stivale2/stivale2_tags.h"
#include "../lib/string.h"

void (*term_write)(const char *string, size_t length) = NULL;

void tty_init()
{
    struct stivale2_struct_tag_terminal* terminal_tag = GetTags()->terminal_tag;

    // If we can't find the terminal, just hang.
    if (terminal_tag == NULL)
    {
        while (1)
        {
            asm ("hlt");
        }
        
    }

    void *term_write_ptr = (void *)terminal_tag->term_write;

    term_write = (void(*)(const char*, size_t))(term_write_ptr);
}

void tty_putchar(char chr)
{
    term_write(&chr, 1);
}

void printk(const char* str)
{
    for (size_t i = 0; str[i]; i++)
    {
        tty_putchar(str[i]);
    }
}