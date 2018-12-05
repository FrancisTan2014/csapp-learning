# Practice Problem 2.53 (solution page 160)
Fill in the following macro definitions to generate the double-precision values +∞, –∞, and –0:

```c
#define POS_INFINITY
#define NEG_INFINITY
#define NEG_ZERO
```

You cannot use any include files (such as math.h), but you can make use of the fact that the largest finite number that can be represented with double precision is around 1.8 × 10308.

## My answer
```c
#define POS_INFINITY 0x7FF0000000000000
#define NEG_INFINITY 0xFFF0000000000000
#define NEG_ZERO 0x1000000000000000 
```

## Answer from the book
```c
#define POS_INFINITY 1e400
#define NEG_INFINITY (–POS_INFINITY)
#define NEG_ZERO (–1.0/POS_INFINITY)
```