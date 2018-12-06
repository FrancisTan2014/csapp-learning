# Practice Problem 3.3 (solution page 326)
Each of the following lines of code generates an error message when we invoke the assembler. Explain what is wrong with each line.

- A. movb $0xF, (%ebx)
- B. movl %rax, (%rsp)
- C. movw (%rax),4(%rsp)
- D. movb %al,%sl
- E. movq %rax,$0x123
- F. movl %eax,%rdx
- G. movb %si, 8(%rbp)

## My answer (I did the italic and empty ones wrong)
- A. 
- B. *the correct instruction should be movq %rax, (%rsp)*
- C. cannot move an integer from one memory to another
- D. 
- E. destination must be a register or memory
- F. *the correct instruction should be movl %eax,%edx*
- G. *the instruction should be movw %si, 8(%rbp)*

## Solution from the book
- movb	$0xF, (%ebx)	**Cannot use %ebx as address register**
- movl	%rax, (%rsp)	**Mismatch between instruction suffix and register ID**
- movw	(%rax),4(%rsp)	**Cannot have both source and destination be memory references**
- movb	%al,%sl		**No register named %sl**
- movl	%eax,$0x123	**Cannot have immediate as destination**
- movl	%eax,%dx	**Destination operand incorrect size**
- movb	%si, 8(%rbp)	**Mismatch between instruction suffix and register ID**