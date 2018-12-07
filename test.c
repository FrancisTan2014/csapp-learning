#include <stdio.h>
// #include <stdint.h>
// #include "ch02/show_byte.h"

void assembly_test(int x, int y);

int main() {
    // short x = 12345;
    // short mx = -x;
    // show_bytes((byte_pointer) &x, sizeof(short));
    // show_bytes((byte_pointer) &mx, sizeof(short));
    assembly_test(3, 4);
    return 0;
}

void assembly_test(int x, int y) {
    int t = x ^ y;
    printf("y=%d\n", y);
    printf("x=%d\n", x);
}