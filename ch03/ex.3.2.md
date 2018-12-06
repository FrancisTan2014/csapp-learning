# Practice Problem 3.2 (solution page 325)
For each of the following lines of assembly language, determine the appropriate instruction suffix based on the operands. (For example, mov can be rewritten as movb, movw, movl, or movq.)

- A. mov___	%eax, (%rsp)  
- B. mov___	(%rax), %dx  
- C. mov___	$0xFF, %bl  
- D. mov___	(%rsp,%rdx,4), %dl  
- E. mov___	(%rdx), %rax  
- F. mov___	%dx, (%rax)  

## My answer
- A. movl
- B. movq wrong
- C. movb
- D. movl wrong
- E. movq
- F. movb wrong

## Solution from the book
- A. movl
- B. movw
- C. movb
- D. movb
- E. movq
- F. movw