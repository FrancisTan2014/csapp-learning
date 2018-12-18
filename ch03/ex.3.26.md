# Practice Problem 3.26 (solution page 336)
A function fun_a has the following overall structure:

```c
long fun_a(unsigned long x) {
	long val = 0;
	while (...){
	  ⋮
	}
	return ...;
}
```

The gcc C compiler generates the following assembly code:

```c
	long fun_a(unsigned long x)
	x in %rdi
1	fun_a:
2	  movl	$0, %eax
3	  jmp	.L5
4	.L6:
5	  xorq	%rdi, %rax
6	  shrq	%rdi			Shift right by 1
7	.L5:
8	  testq	%rdi, %rdi
9	  jne	.L6
10	  andl	$1, %eax
11	  ret
```

Reverse engineer the operation of this code and then do the following:

- A. Determine what loop translation method was used.

- B. Use the assembly-code version to fill in the missing parts of the C code.

- C. Describe in English what this function computes.

## My answer
- A. guarded-do translation
- B. 
    ```c
    long fun_a(unsigned long x) {
        long val = 0;
        while (x != 0){
            val ^= x;
            x = x >> 1;
        }
        return val & 0x1;
    }
    ```
- C. 

## Solution from the book
- C. This code computes the **parity** of argument x. That is, it returns 1 if there is an odd number of ones in x and 0 if there is an even number.