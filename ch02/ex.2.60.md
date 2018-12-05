# Homework Problem 2.60
Suppose we number the bytes in a w-bit word from 0 (least significant) to w/8 – 1 (most significant). Write code for the following C function, which will return an unsigned value in which byte i of argument x has been replaced by byte b:

```c
unsigned replace_byte (unsigned x, int i, unsigned char b);
```

Here are some examples showing how the function should work:

```c
replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678  
replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB
```

## My answer
```c
# include <stdio.h>

unsigned replace_byte (unsigned x, int i, unsigned char b);

int main() {
    unsigned result = replace_byte(0x12345678, 2, 0xAB);
    printf("for test case replace_byte(0x12345678, 2, 0xAB), expected result is 0x12AB5678, and the actural result is 0x%x\n", result);
    result = replace_byte(0x12345678, 0, 0xAB);
    printf("for test case replace_byte(0x12345678, 0, 0xAB), expected result is 0x123456AB, and the actural result is 0x%x\n", result);
    return 0;
}

unsigned replace_byte (unsigned x, int i, unsigned char b) {
    if (i < 0 || i > 4) {
        return -1;
    }
    const unsigned short SHIFT_CNT = i * 8;
    unsigned mask;
    if (i == 4) {
        mask = 0xFFFFFFFF;
    } else {
        // make the lower bits of mask all ones
        // for example 0x0000FFFF
        mask = (1 << SHIFT_CNT) - 1;
    }
    // store the lower bits of x
    unsigned lower_bits = x & mask;
    // first, drop the lower bits with right shift operation on x,
    // then replace the lowest byte with argument b
    unsigned combined = (x >> SHIFT_CNT) & 0xFFFFFF00 | b;

    // do left shift operation, then recover the lower bits
    // we get the correct result
    return (combined << SHIFT_CNT) | lower_bits;
}
```