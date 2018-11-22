# Practice Problem 2.16
Fill in the table below showing the effects of the different shift operations on single-byte quantities. The best way to think about shift operations is to work with binary representations. Convert the initial values to binary, perform the shifts, and then convert back to hexadecimal. Each of the answers should be 8 binary digits or 2 hexadecimal digits.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;x&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;x << 3 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Logical x >> 2 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Arithmetic x >> 2 
Hex | Binary | Binary | Hex | Binary | Hex | Binary | Hex
---|---|---|---|---|---|---|---
0xC3 | 11000011 | 00011000 | 0x14 | 00110000 | 0x30 | 00110000 | 0x30
0x75 | 01110101 | 10101000 | 0xB4 | 00011101 | 0x1D | 11011101 | 0xDD
0x87 | 10000111 | 00111000 | 0x38 | 00100001 | 0x21 | 11100001 | 0xE1
0x66 | 01100110 | 00110000 | 0x30 | 00011001 | 0x19 | 11011001 | 0xD9

## Right Answer
Hex | Binary | Binary | Hex | Binary | Hex | Binary | Hex
---|---|---|---|---|---|---|---
0xC3 | 11000011 | 00011000 | 0x18 | 00110000 | 0x30 | 11110000 | 0xF0
0x75 | 01110101 | 10101000 | 0xA8 | 00011101 | 0x1D | 00011101 | 0x1D
0x87 | 10000111 | 00111000 | 0x38 | 00100001 | 0x21 | 11100001 | 0xE1
0x66 | 01100110 | 00110000 | 0x30 | 00011001 | 0x19 | 00011001 | 0x19

# Summary
The difference between right logical shifting and right arithmetic shifting is that former operating always takes 0 as filling value while latter one takes the most significant bit  of the original value as filling value. The mistake I have made was that I took the least significant bit to fill the left bits when I did right shifting of arithmetic.

# Draft
x << 3
01110101
   10101000

Logical x >> 2
  01100110
00011001

Arithmetic x >> 2
  11000011
00110000