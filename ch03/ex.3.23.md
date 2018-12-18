#Practice Problem 3.23 (solution page 334)
For the C code
```c
long dw_loop(long x) {
    long y = x*x;
    long *p = &x;
    long n = 2*x;
    do {
       x += y;
       (*p)++;
       n--;
    } while (n > 0);
    return x;
}
```
gcc generates the following assembly code:
```c
	long dw_loop(long x)
	x initially in %rdi
1	dw_loop:
2	  movq	%rdi, %rax // Set Result=x
3	  movq	%rdi, %rcx // Set y=x
4	  imulq	%rdi, %rcx // Compute y *= x
5	  leaq	(%rdi,%rdi), %rdx // Compute n = 2*x
6	.L2:                        // loop:
7	  leaq	1(%rcx,%rax), %rax  // Compute Result = x + y + 1
8	  subq	$1, %rdx // Compute n -= 1
9	  testq	%rdx, %rdx // Test n > 0
10	  jg	.L2 // If >, goto loop
11	  rep; ret
```

- A. Which registers are used to hold program values x, y, and n?

- B. How has the compiler eliminated the need for pointer variable p and the pointer dereferencing implied by the expression (*p)++?

- C. Add annotations to the assembly code describing the operation of the program, similar to those shown in Figure 3.19(c).

## My answer
- A. x in %rdi, y in %rcx, n in %rdx, respectively.
- B. line 7 indicates the result of ```x + y + 1```, and it is the same as original C code 
```c
    x += y;
    (*p)++; // equals to x += 1;
```
- C. 
```c
	long dw_loop(long x)
	x initially in %rdi
1	dw_loop:
2	  movq	%rdi, %rax
3	  movq	%rdi, %rcx
4	  imulq	%rdi, %rcx
5	  leaq	(%rdi,%rdi), %rdx
6	.L2:
7	  leaq	1(%rcx,%rax), %rax
8	  subq	$1, %rdx
9	  testq	%rdx, %rdx
10	  jg	.L2
11	  rep; ret
```

## Solution to Problem 3.23 (page 222)
The code generated when compiling loops can be tricky to analyze, because the compiler can perform many different optimizations on loop code, and because it can be difficult to match program variables with registers. This particular example demonstrates several places where the assembly code is not just a direct translation of the C code.

- A. Although parameter x is passed to the function in register ```%rdi```, we can see that the register is never referenced once the loop is entered. Instead, we can see that registers ```%rax```, ```%rcx```, and ```%rdx``` are initialized in lines 2–5 to x, x*x, and x+x. We can conclude, therefore, that these registers contain the program variables.

- B. The compiler determines that pointer p always points to x, and hence the expression (*p)++ simply increments x. It combines this incrementing by 1 with the increment by y, via the leaq instruction of line 7.

- C. The annotated code is as follows:
```c
	long dw_loop(long x)
	x initially in %rdi
1	dw_loop:
2	movq	%rdi, %rax		Copy x to %rax
3	movq	%rdi, %rcx
4	imulq	%rdi, %rcx		Compute y = x*x
5	leaq	(%rdi,%rdi), %rdx	Compute n = 2*x
6	.L2:			    loop:
7	leaq	1(%rcx,%rax), %rax	Compute x += y + 1
8	subq $1, %rdx			Decrement n
9	testq	%rdx, %rdx		Test n
10	jg	.L2			If > 0, goto loop
11	rep;	ret			Return
```