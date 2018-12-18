# Practice Problem 3.24 (solution page 335)
For C code having the general form
```c
long loop_while(long a, long b)
{
    long result = __________;
    while (__________) {
        result = __________;
        a = __________;
    }
    return result;
}
```

gcc, run with command-line option -0g, produces the following code:

```c
	long loop_while(long a, long b)
	a in %rdi, b in %rsi
1	loop_while:
2	  movl	$1, %eax
3	  jmp	.L2
4	.L3:
5	  leaq	(%rdi,%rsi), %rdx
6	  imulq	%rdx, %rax
7	  addq	$1, %rdi
8	.L2:
9	  cmpq	%rsi, %rdi
10	  jl	.L3
11	  rep; ret
```

We can see that the compiler used a jump-to-middle translation, using the jmp instruction on line 3 to jump to the test starting with label .L2. Fill in the missing parts of the C code.

## My answer
```c
long loop_while(long a, long b)
{
    long result = 1;
    while (a < b) {
        result = result * (a + b);
        a = a + 1;
    }
    return result;
}
```