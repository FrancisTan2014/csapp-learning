# Practice Problem 2.47 (solution page 158)
Consider a 5-bit floating-point representation based on the IEEE floating-point format, with one sign bit, two exponent bits (k = 2), and two fraction bits (n = 2). The exponent bias is 2^(2–1) – 1 = 1.

The table that follows enumerates the entire nonnegative range for this 5-bit floating-point representation. Fill in the blank table entries using the following directions:

e: The value represented by considering the exponent field to be an unsigned integer

E: The value of the exponent after biasing

2^E: The numeric weight of the exponent

f: The value of the fraction

M: The value of the significand

2^E × M: The (unreduced) fractional value of the number

V: The reduced fractional value of the number

Decimal: The decimal representation of the number

Express the values of 2E, f, M, 2E × M, and V either as integers (when possible) or as fractions of the form , where y is a power of 2. You need not fill in entries marked —.

Bits | e | E | 2^E | f | M | 2^E * M | V | Decimal
---|---|---|---|---|---|---|---|---
0 00 00 | | 0 | 1 | 0/4 | 0/4 | 0/4 | 0/4 | 0
0 00 01 | | 0 | 1 | 1/4 | 1/4 | 1/4 | 1/4 | 0.25
0 00 10 | | 0 | 1 | 2/4 | 2/4 | 2/4 | 2/4 | 0.5
0 00 11 | | 0 | 1 | 3/4 | 3/4 | 3/4 | 3/4 | 0.75
0 01 00 | | 0 | 1 | 0/4 | 0/4 | 0/4 | 0/4 | 0/4
0 01 01 | | 0 | 1 | 1/4 | 1/4 | 1/4 | 1/4 | 1/4
0 01 10 | | 0 | 1 | 2/4 | 2/4 | 2/4 | 2/4 | 2/4
0 01 11 | | 0 | 1 | 3/4 | 3/4 | 3/4 | 3/4 | 3/4
0 10 00 | | 1 | 2 | 0/4 | 0/4 | 0/4 | 0/4 | 0/4
0 10 01 | | 1 | 2 | 1/4 | 1/4 | 2/4 | 2/4 | 2/4
0 10 10 | | 1 | 2 | 2/4 | 2/4 | 4/4 | 4/4 | 4/4
0 10 11 | | 1 | 2 | 3/4 | 3/4 | 6/4 | 6/4 | 6/4
0 11 00 | | - | - | - | - | - | +∞ | - 
0 11 01 | | - | - | - | - | - | NaN | - 
0 11 10 | | - | - | - | - | - | NaN | - 
0 11 11 | | - | - | - | - | - | NaN | - 