# Practice Problem 2.49 (solution page 159)
- A. For a floating-point format with an n-bit fraction, give a formula for the smallest positive integer that cannot be represented exactly (because it would require an (n + 1)-bit fraction to be exact). Assume the exponent field size k is large enough that the range of representable exponents does not provide a limitation for this problem.

- B. What is the numeric value of this integer for single-precision format (n = 23)?

## My answer 
- A. -2^k + 2
- B. -126

## Right answer
- A. The number has binary representation 1, followed by n zeros, followed by 1, giving value 2^(n+1) + 1.
- B. When n = 23, the value is 2^24 + 1 = 16,777,217.