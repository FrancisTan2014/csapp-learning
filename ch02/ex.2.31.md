# Practice Problem 2.31 (solution page 153)
Your coworker gets impatient with your analysis of the overflow conditions for two's-complement addition and presents you with the following implementation of tadd_ok:

```c
/* Determine whether arguments can be added without overflow */
/* WARNING: This code is buggy. */
int tadd_ok(int x, int y) {
    int sum = x+y;
    return (sum-x == y) && (sum-y == x);
}
```

You look at the code and laugh. Explain why.

## My answer
> I don't really understand this situation. Maybe after learning the procedure of minus between tow's-complement then I can explain it.