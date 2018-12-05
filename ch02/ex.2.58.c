/**
 * Practice Problem 2.58
 * Write a procedure is_little_endian that will return 1
 * when compiled and run on a little-endian machine, and 
 * will return 0 when compiled and run on a big-endian machine. 
 * This program should run on any machine, regardless of its word size.
 */

#include <stdio.h>
#include "show_byte.h"

int is_little_endian();

int main() {
    int isLittle = is_little_endian();
    printf("this result is: %d\n", isLittle);
    if (isLittle) {
        printf("so this machine uses little endian to represent the bytes\n");
    } else {
        printf("so this machine uses big endian to represent the bytes\n");
    }
    return 0;
}

int is_little_endian() {
    int n = 0xFF000000;
    byte_pointer bp = (byte_pointer) &n;
    return *bp == 0x00;
}
