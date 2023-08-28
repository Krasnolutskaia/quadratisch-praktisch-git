#include <stdio.h>
#include <stdarg.h>
#include "color_print.h"


void color_print(const char COLOR[], const char *format, ...)
{
    va_list ptr;
    printf("%s", COLOR);
    va_start(ptr, format);
    vprintf(format, ptr);
    va_end(ptr);
    printf(COLOR_RESET "\n");
}
