#include <stdio.h>
#include "show_byte.h"

float sum_elements_withbug(float a[], unsigned length);
float sum_elements_fixed(float a[], unsigned length);

int main() {
    float a[] = { 0.1, 0.2, 0.3 };
    unsigned length = 0;
    int i = 1;
    unsigned n = length - 1;
    show_bytes((byte_pointer) &n, sizeof(unsigned));
    printf("%u %d\n", length-1, length-1);
    printf("i <= length-1 %d\n", i <= length-1);

    float res = sum_elements_fixed(a, 0);
    printf("the result of sum_elements_fixed is: %f\n", res);
    res = sum_elements_withbug(a, 0);
    printf("the result of sum_elements_withbug is: %f\n", res);

    return 0;
}

float sum_elements_withbug(float a[], unsigned length) {
    int i;
    float result = 0;

    for (i = 0; i <= length-1; i++) {
        result += a[i];
    }
    return result;
}

float sum_elements_fixed(float a[], unsigned length) {
    int i;
    float result = 0;

    for (i = 0; i < length; i++) {
        result += a[i];
    }
    return result;
}