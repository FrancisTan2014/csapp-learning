# Practice Problem 2.23 (solution page 150)
Consider the following C functions:

```C
int fun1(unsigned word) {
    return (int) ((word << 24) >> 24);
}

int fun2(unsigned word) {
    return ((int) word << 24) >> 24;
}
```
Assume these are executed as a 32–bit program on a machine that uses two's-complement arithmetic. **Assume also that right shifts of signed values are performed arithmetically, while right shifts of unsigned values are performed logically**.  
    **A.** Fill in the following table showing the effect of these functions for several example arguments. You will find it more convenient to work with a hexadecimal representation. Just remember that hex digits 8 through F have their most significant bits equal to 1.  
    **B.** Describe in words the useful computation each of these functions performs.

> PS: Pay attention to the sentence which was emphasized of describing the rules on right shifting. I got wrong answers because of not reading the problem precisely.  
> Logical Right Shift: fills the left end with *k* zeros.  
> Arithmetic Right Shift: fills the left end with *k* repitions of the most significant bit. For example, 0x1100 >> 2 equals to 0x1111, 0x0101 >> 2 equals to 0x0001.

## A.
w | fun1(w) | fun2(w)
---|---|---
0x00000076 | 0x00000076 | 0x00000076
0x87654321 | 0x00000021 | 0x00000021
0x000000C9 | 0xFFFFFFC9 (answer is 0x000000C9) | 0xFFFFFFC9
0xEDCBA987 | 0xFFFFFF87 (answer is 0x00000087) | 0xFFFFFF87

0x00000076 << 24  
      0x76000000 >> 24  
0x00000076  

0x87654321 << 24  
      0x21000000 >> 24  
0x00000021

0x000000C9 << 24  
      0xC9000000 >> 24  
0xFFFFFFC9  

0xEDCBA987 << 24  
      0x87000000 >> 24  
0xFFFFFF87

## B.
func1: It extracts a value from the lower 8-bit of the argument, giving a number ranging between 0 and 255.  
func2: It does the same thing as func1, but it also performs sign extension, and giving a number ranging between -127 and 128.