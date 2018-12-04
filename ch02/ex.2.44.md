#Practice Problem 2.44 (solution page 157)
Assume data type int is 32 bits long and uses a two's-complement representation for signed values. Right shifts are performed arithmetically for signed values and logically for unsigned values. The variables are declared and initialized as follows:

```c
int x = foo();	 /* Arbitrary value */
int y = bar();	 /* Arbitrary value */

unsigned ux = x;
unsigned uy = y;
```

For each of the following C expressions, either (1) argue that it is true (evaluates to 1) for all values of x and y, or (2) give values of x and y for which it is false (evaluates to 0):

- A. (x > 0) || (x-1 < 0)
- B. (x & 7) != 7 || (x<<29 < 0)
- C. (x * x) >= 0
- D. x < 0 || -x <= 0
- E. x > 0 || -x > = 0
- F. x+y == uy+ux
- G. x*~y + uy*ux == -x

## Answer
- A. While gives x = 0x80000000, x-1 will product 0.
- B. The expression will always be true. As we know that the negative proposition of this expression is ```(x & 7) == 7 && (x << 29 >= 0)```, if the negative proposition is false, then the original proposition must be true. For formmer sub expression of the negative proposition, it is true only when the lowest 4 bits of x is 0111, in this case, x << 29 is always a negative number. So the negative proposition is always false which indicates that the original proposition is always true.