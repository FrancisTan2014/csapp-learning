# Practice Problem 3.20 (solution page 333)
In the following C function, we have left the definition of operation OP incomplete:
```c
#define OP __________/* Unknown operator */
long arith(long x) {
	return x OP 8;
}
```
When compiled, gcc generates the following assembly code:
```c
	long arith(long x)
	x in %rdi
arith:
  leaq 7(%rdi), %rax
  testq %rdi, %rdi
  cmovns %rdi, %rax
  sarq $3, %rax
  ret
```

- A. What operation is OP?
- B. Annotate the code to explain how it works.

## My answer
- A. 
- B. 
    ```c
    long arith(long x) {
        return x < 0 ? 8x : 8*(7+x);
    }
    ```

## Solution from the book
- A. The operator is `/'. We see this is an example of dividing by a power of 3 by right shifting (see Section 2.3.7). Before shifting by , we must add a bias of  when the dividend is negative.

- B. Here is an annotated version of the assembly code:

```c
	long arith(long x)
	x in %rdi
arith:
  leaq	7(%rdi), %rax	temp = x+7
  testq	%rdi, %rdi	    Text x
  cmovns	%rdi, %rax	If x>= 0, temp = x
  sarq	$3, %rax	    result = temp >> 3 (= x/8)
  ret
```
The program creates a temporary value equal to , in anticipation of x being negative and therefore requiring biasing. The cmovns instruction conditionally changes this number to x when , and then it is shifted by 3 to generate x/8.