# Practice Problem 3.21 (solution page 333)
Starting with C code of the form
```c
long test(long x, long y) {
	long val = __________;
	if (__________) {
		if (__________)
			val = __________;
		else
			val = __________;
	} else if (__________)
		val = __________;
	return val;
}
```
gcc generates the following assembly code:
```c
	long test(long x, long y)
	x in %rdi, y in %rsi
	test:
	  leaq	0(,%rdi,8), %rax
	  testq	%rsi, %rsi
	  jle	.L2
	  movq %rsi, %rax
	  subq %rdi, %rax
	  movq %rdi, %rdx
	  andq %rsi, %rdx
	  cmpq %rsi, %rdi
	  cmovge %rdx, %rax
	  ret
	.L2:
	  addq %rsi, %rdi
	  cmpq $-2, %rsi
	  cmovle %rdi, %rax
	  ret
```
Fill in the missing expressions in the C code.

## My answer
```c
long test(long x, long y) {
    long val = 8*x;
    if (y > 0) {
        if (x < y)
            val = x - y;
        else
            val = x & y;
    } else if (y <= 0)
        val = (x + y > -2) ? (x + y) : y;
    return val;
}
```

## Solution from the book
```c
long test(long x, long y) {
    long val = 8*x;
    if (y > 0) {
        if (x < y)
            val = y - x;
        else
            val = x & y;
    } else if (y <= -2)
        val = x + y;
    return val;
}
```