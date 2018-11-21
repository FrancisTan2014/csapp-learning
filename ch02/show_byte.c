#include <stdio.h>
#include "show_byte.h"

void show_bytes(byte_pointer start, int len) {
    for (int i = 0; i < len; i++) {
        printf("%.2x ", start[i]);
    }
    printf("\n");
}