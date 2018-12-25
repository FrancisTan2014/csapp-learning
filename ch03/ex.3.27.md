# Practice Problem 3.27 (solution page 336)
Write goto code for fact_for based on first transforming it to a while loop and then applying the guarded-do transformation.

## My answer
C code
```c
long fact_for_guard_do(long n) {
    long i = n;
    long result = 1;
    if (i <= 1) {
        goto done;
    }

loop:
    result *= i;
    i--;
    if (i != 1) {
        goto loop;
    }

done:
    return result;
}
```

Assembly code
```c
    long fact_for_guard_do(long n)
    n in %rdi
fact_for_guard_do:
    movq %rdi, %rax         Set result = n
    movq %rdi, %rdx         Set i = n
    cmpq $1, %rdx           Compare 1:i
    jle .L7                 if <=, goto done
.L6:                    loop:
    imulq %rdx, %rax        Compute result *= i
    subq $1, %rdx           Decrement i
    cmpq $1, %rdx           Compare 1:i
    jne .L6                 if !=, goto loop
    rep; ret                Return
.L7:                    done:
    movq $1, %rax           Compute result = 1
    ret                     Return
```

## Solution from the book
This exercise is intended to reinforce your understanding of how loops are implemented.
```c
long fact_for_gd_goto(long n)
{
	long i = 2;
	long result = 1;
	if (n <= 1)
	  goto done;
loop:
	result *= i;
	i++;
	if (i <= n)
	  goto loop;
done:
	return result;
}
```