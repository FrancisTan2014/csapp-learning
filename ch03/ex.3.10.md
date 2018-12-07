#Practice Problem 3.10 (solution page 329)
In the following variant of the function of Figure 3.11(a), the expressions have been replaced by blanks:

```c
long arith2(long x, long y, long z)
{
  long t1 = __________;
  long t2 = __________;
  long t3 = __________;
  long t4 = __________;
  return t4;
}
```

The portion of the generated assembly code implementing these expressions is as follows:

```c
  long arith2(long x, long y, long z)
  x in %rdi, y in %rsi, z in %rdx
arith2:
  orq	%rsi, %rdi
  sarq	$3, %rdi
  notq	%rdi
  movq	%rdx, %rax
  subq	%rdi, %rax
  ret
```

Based on this assembly code, fill in the missing portions of the C code.

## My answer
```c
long arith2(long x, long y, long z)
{
  long t1 = x | y;
  long t2 = t1 >> 3;
  long t3 = ~t2;
  long t4 = z - t3;
  return t4;
}
```