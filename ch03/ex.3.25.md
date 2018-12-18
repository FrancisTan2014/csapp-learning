# Practice Problem 3.25 (solution page 335)
For C code having the general form
```c
long loop_while2(long a, long b)
{
	long result= __________;
	while(__________) {
		result = __________;
		b= __________;
	}
	return result;
}
```

gcc, run with command-line option -01, produces the following code:

```c
	a in %rdi, b in %rsi
1	loop_while2:
2	testq	%rsi, %rsi
3	jle	.L8
4	movq	%rsi, %rax
5	.L7:
6	imulq	%rdi, %rax
7	subq	%rdi, %rsi
8	testq	%rsi, %rsi
9	  jg	.L7
10	  rep; ret
11	.L8:
12	  movq	%rsi, %rax
13	  ret
```

We can see that the compiler used a guarded-do translation, using the jle instruction on line 3 to skip over the loop code when the initial test fails. Fill in the missing parts of the C code. Note that the control structure in the assembly code does not exactly match what would be obtained by a direct translation of the C code according to our translation rules. In particular, it has two different ret instructions (lines 10 and 13). However, you can fill out the missing portions of the C code in a way that it will have equivalent behavior to the assembly code.

## My answer
```c
long loop_while2(long a, long b)
{
	long result = b;
	while(b > 0) {
		result = result * a;
		b = b - a;
	}
	return result;
}
```