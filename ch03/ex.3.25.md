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
```

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