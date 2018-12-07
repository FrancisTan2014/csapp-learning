# Practice Problem 3.11 (solution page 329)
It is common to find assembly-code lines of the form

```c
xorq %rdx,%rdx
```

in code that was generated from C where no exclusive-or operations were present.

- A. Explain the effect of this particular exclusive-or instruction and what useful operation it implements.

- B. What would be the more straightforward way to express this operation in assembly code?

- C. Compare the number of bytes to encode these two different implementations of the same operation.

## My answer (I did it all wrong)
- A. add %rdx by itself and stored the result in %rdx
- B. salq $1,%rdx
- C. absolutely the same

## Solution from the book
- A. This instruction is used to set register %rdx to zero, exploiting the property that x ^ x = 0 for any x. It corresponds to the C statement x = 0.

- B. A more direct way of setting register %rdx to zero is with the instruction movq $0,%rdx.

- C. Assembling and disassembling this code, however, we find that the version with xorq requires only 3 bytes, while the version with movq requires 7. Other ways to set %rdx to zero rely on the property that any instruction that updates the lower 4 bytes will cause the high-order bytes to be set to zero. Thus, we could use either xorl %edx,%edx (2 bytes) or movl $0,%edx (5 bytes).