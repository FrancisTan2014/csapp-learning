#include <stdio.h>
#include "show_byte.h"

int main() {
    int val = 0x87654321;
    byte_pointer start = (byte_pointer) &val;
    show_bytes(start, 1);
    show_bytes(start, 2);
    show_bytes(start, 3);

    return 0;
}