#Practice Problem 3.12 (solution page 329)
Consider the following function for computing the quotient and remainder of two unsigned 64-bit numbers:

```c
void uremdiv(unsigned long x, unsigned long y,
  		unsigned long *qp, unsigned long *rp) {
  	unsigned long q = x/y;
  	unsigned long r = x%y;
  	*qp = q;
  	*rp = r;
}
```

Modify the assembly code shown for signed division to implement this function.

## My answer
```c
  void uremdiv(unsigned x, unsigned y, unsigned *qp, unsigned *rp)
  x in %rdi, y in %rsi, qp in %rdx, rp in %rcx

    uremdiv:
        movq %rdx,%r8
        movq %rdi,%rax
        // cqto
        movl $0,%edx
        divq %rsi
        movq %rax,(%r8)
        movq %rdx,(%rcx)
        ret
```