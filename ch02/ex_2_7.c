#include <stdio.h>
#include <string.h>
#include "show_byte.h"

int main() {
    const char *s = "abcdef";
    show_bytes((byte_pointer)s, strlen(s));

    return 0;
}