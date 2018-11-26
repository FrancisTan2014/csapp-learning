# Practice Problem 2.24
Suppose we truncate a 4–bit value (represented by hex digits 0 through F) to a 3–bit value (represented as hex digits 0 through 7.) Fill in the table below showing the effect of this truncation for some cases, in terms of the unsigned and two's-complement interpretations of those bit patterns.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="text-decoration: underline;">Hex</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="text-decoration: underline;">Unsigned</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="text-decoration: underline;">Two's complement</span>
Original | Truncated | Original | Truncated | Original | Truncated
---:|:---|---:|:---|---:|:---
0 | 0 | 0 | 0 | 0 | 0
2 | 2 | 2 | 2 | 2 | 2
9 | 1 | 9 | 1 | -7 | 1
B | 3 | 11 | 3 | -5 | 3
F | 7 | 15 | 7 | -1 | -1

Unsigned(B2U)  
1111 -> 111 