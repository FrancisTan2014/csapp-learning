/**
 * Homework Problem 2.59
 * Write a C expression that will yield a word consisting
 * of the least significant byte of x and the remaining 
 * bytes of y. For operands x = 0x89ABCDEF and y = 0x76543210,
 * this would give 0x765432EF.
 */

#include <stdio.h>
#include "show_byte.h"

int main() {
    int x = 0x89ABCDEF;
    int y = 0x76543210;
    int result = (x & 0x000000FF) | (y & 0xFFFFFF00);
    show_bytes((byte_pointer) &result, 4);
    return 0;
}