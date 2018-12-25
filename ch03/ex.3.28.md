#Practice Problem 3.28 (solution page 336)
A function fun_b has the following overall structure:
```c
long fun_b(unsigned long x) {
     long val = 0;
     long i;
     for ( ...; ...; ...) {
	 ⋮
     }
     return val;
}
```
The gcc C compiler generates the following assembly code:
```c
	long fun_b(unsigned long x)
	x in %rdi
1	fun_b:
2	movl	$64, %edx
3	movl	$0, %eax
4  .L10:
5	movq	%rdi, %rcx
6	andl	$1, %ecx
7	addq	%rax, %rax
8	orq	%rcx, %rax
9	shrq	%rdi		Shift right by 1
10	subq	$1, %rdx
11	jne	.L10
12	rep; ret
```
Reverse engineer the operation of this code and then do the following:

- A. Use the assembly-code version to fill in the missing parts of the C code.

- B. Explain why there is neither an initial test before the loop nor an initial jump to the test portion of the loop.

- C. Describe in English what this function computes.

## My answer
- A.
```c
long fun_b(unsigned long x) {
    long val = 0;
    long i;
    for (i = 64; i != 0; x >>= 1,i--) {
        val *= 2;
        val |= x & 1;
    }
    return val;
} 
```

## Solution to Problem 3.28 (page 231)
This problem is trickier than Problem 3.26, since the code within the loop is more complex and the overall operation is less familiar.

- A. Here is the original C code:
    ```c
    long fun_b(unsigned long x) {
        long val = 0;
        long i;
        for (i = 64; i != 0; i–) {
            val = (val << 1) | (x & 0x1);
            x >>= 1;
        }
        return val;
    }
    ```

- B. The code was generated using the guarded-do transformation, but the compiler detected that, since ```i``` is initialized to 64, it will satisfy the test ```i ≠ 0```, and therefore the initial test is not required.

- C. This code reverses the bits in ```x```, creating a mirror image. It does this by shifting the bits of x from left to right, and then filling these bits in as it shifts val from right to left.