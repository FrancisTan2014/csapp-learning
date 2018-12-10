# Practice Problem 3.15 (solution page 330)
In the following excerpts from a disassembled binary, some of the information has been replaced by X's. Answer the following questions about these instructions.

- A.
What is the target of the je instruction below? (You do not need to know anything about the callq instruction here.)
```c
4003fa: 74 02	je	XXXXXX
4003fc: ff d0	callq	*%rax
```

- B.
What is the target of the je instruction below?
```c
40042f: 74 f4	je	XXXXXX
400431: 5d	pop	%rbp
```

- C.
What is the address of the ja and pop instructions?
```c
XXXXXX: 77 02	ja	400547
XXXXXX: 5d	pop	%rbp
```

- D.
In the code that follows, the jump target is encoded in PC-relative form as a 4-byte two's-complement number. The bytes are listed from least significant to most, reflecting the little-endian byte ordering of x86-64. What is the address of the jump target?
```c
4005e8: e9 73 ff ff ff	jmpq	XXXXXXX
4005ed: 90		nop
```

## My answer
- A. ```4004fe``` is the target of the ```je``` instruction. 
- B. ```400425``` is the target of the ```je``` instruction.
- C. ```400443``` and ```400441``` are the address of the ```ja``` and ```pop``` instructions, respectively.
- D. 

## Solution from the book
- C. According to the annotation produced by the disassembler, the jump target is at absolute address ```0x400547```. According to the byte encoding, this must be at an address 0x2 bytes beyond that of the pop instruction. Subtracting these gives address ```0x400545```. Noting that the encoding of the ```ja``` instruction requires 2 bytes, it must be located at address 0x400543. These are confirmed by examining the original disassembly:
    ```c
    400543: 77 02	ja	400547
    400545: 5d	pop	%rbp
    ```
- D. Reading the bytes in reverse order, we can see that the target offset is ```0xffffff73```, or decimal ```-141```. Adding this to ```0x0x4005ed``` (the address of the nop instruction) gives address ```0x400560```:
    ```c
    4005e8: e9 73 ff ff ff	jmpq	400560
    4005ed: 90		nop
    ```