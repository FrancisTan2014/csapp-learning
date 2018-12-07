# Practice Problem 3.8 (solution page 328)
Assume the following values are stored at the indicated memory addresses and registers:

Address | Value | Register | Value
---|---|---|---
0x100 | 0xFF | %rax | 0x100
0x108 | 0xAB | %rcx | 0x1
0x110 | 0x13 | %rdx | 0x3
0x118 | 0x11	

Fill in the following table showing the effects of the following instructions, in terms of both the register or memory location that will be updated and the resulting value:

Instruction | Destination | Value
---|---|---
addq %rcx,(%rax) | __________ | __________
subq %rdx,8(%rax) | __________ | __________
imulq $16,( %rax,%rdx,8) | __________ | __________
incq 16(%rax) | __________ | __________
decq %rcx | __________ | __________
subq %rdx,%rax | __________ | __________

## My answer
Instruction | Destination | Value | Effect
---|---|---|---
addq %rcx,(%rax) | Addr(0x100) | 0x100 | Change the value of memory(0x100) to 0x100 
subq %rdx,8(%rax) | Addr(0x108) | 0xA8 | Change the value of memory(0x108) to 0xA8
imulq $16,( %rax,%rdx,8) | Addr(0x118) | 0x110 | Change the value of memory(0x118) to 0x110
incq 16(%rax) | Addr(0x110) | 0x101 *(right answer is 0x14)* |  Change the value of memory(0x100) to 0x101
decq %rcx | %rcx | 0x0 | Change the value of %rcx to 0x0
subq %rdx,%rax | %rax | 0xFD | Change the value of %rcx to 0xFD