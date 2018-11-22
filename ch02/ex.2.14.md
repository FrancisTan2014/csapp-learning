# Practice Problem 2.14
Suppose that x and y have byte values 0x66 and 0x39, respectively. Fill in the following table indicating the byte values of the different C expressions:

x  = 0x66 = 01100110  
y  = 0x39 = 00111001  
~x = 0x99 = 10011001    
~y = 0xc6 = 11000110
!y = 0x00 = 00000000

Expression | Value | Expression | Value
---|---|---|---
x & y | 0x20(00100000) | x && y | 0x01
x or y | 0x7f(01111111) | x oror y | 0x01
~x or ~y | 0xdf(11011111) | !x oror !y | 0x00
x & !y | 0x00(00000000) | x && ~y | 0x01