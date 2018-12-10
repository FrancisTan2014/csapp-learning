#Practice Problem 3.16 (solution page 331)
When given the C code
```c
void cond(long a, long *p)
{
  if (p && a > *p)
  	*p = a;
}
```
gcc generates the following assembly code:
```c
  void cond(long a, long *p)
  a in %rdi, p in %rsi
cond:
  testq %rsi, %rsi
  je .L1
  cmpq %rdi, (%rsi)
  jge .L1
  movq %rdi, (%rsi)
.L1:
  rep; ret
```

- A. Write a goto version in C that performs the same computation and mimics the control flow of the assembly code, in the style shown in Figure 3.16(b). You might find it helpful to first annotate the assembly code as we have done in our examples.

- B. Explain why the assembly code contains two conditional branches, even though the C code has only one if statement.

## My answer
- A.
```c
void cond(long a, long *p)
{
  if (!p) {
      jump done;
  }
  if (a <= *p) {
      jump done;
  }
  *p = a;
  done:
    return;
}
```

- B. I think the reason is that two subexpressions in the if statement needs to be computed which will be done by two classes of assembly code.

## Solution from the book
- A.
```c
void goto_cond(long a, long *p) {
	if (p == 0)
	  goto done;
	if (*p >= a)
	  goto done;
	*p = a;
done:
	return;
}
```

- B. The first conditional branch is part of the implementation of the && expression. If the test for p being non-null fails, the code will skip the test of a > *p.