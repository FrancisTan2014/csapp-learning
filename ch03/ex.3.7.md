#Practice Problem 3.7 (solution page 328)
Consider the following code, in which we have omitted the expression being computed:

```c
long scale2(long x, long y, long z) {
  long t= __________;
  return t;
}
```

Compiling the actual function with gcc yields the following assembly code:

```c
  long scale2(long x, long y, long z)
  x in %rdi, y in %rsi, z in %rdx
scale2:
  leaq	(%rdi,%rdi,4), %rax // 5x
  leaq	(%rax,%rsi,2), %rax // 5x + 2y
  leaq (%rax,%rdx,8), %rax // 5x + 2y + 8z
  ret
```

Fill in the missing expression in the C code.

## My answer
```
long scale2(long x, long y, long z) {
  long t = 5x + 2y + 8z;
  return t;
}
```