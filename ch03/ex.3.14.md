#Practice Problem 3.14 (solution page 330)
The C code
```c
int test(data_t a) {
  return a TEST 0;
}
```
shows a general comparison between argument a and 0, where we can set the data type of the argument by declaring data_t with a typedef, and the nature of the comparison by declaring TEST with a #define declaration. The following instruction sequences implement the comparison, where a is held in some portion of register %rdi. For each sequence, determine which data types data_t and which comparisons TEST could cause the compiler to generate this code. (There can be multiple correct answers; list all correct ones.)

- A.
```
testq	%rdi, %rdi
setge	%al
```
- B.
```
testw	%di, %di
sete	%al
```
- C.
```
testb	%dil, %dil
seta	%al
```
- D.
```
testl	%edi, %edi
setle	%al
```

## My answer
- A. The suffix ```q``` and the register identifiers indicate 64-bit operands while the comparison is for two's-complement ```>=```. We can infer that ```data_t``` must be ```long```.
- B. The suffix ```w``` and register identifiers indicate 16-bit operands while the comparison is for unsigned ```==```. We can infer that ```data_t``` must be ```unsigned short```.
- C. The suffix ```b``` and register identifiers indicate 8-bit operands while the comparison is for unsigned ```>```. We can infer that ```data_t``` must be ```unsigned char```.
- D. The suffix ```l``` and register identifiers indicate 32-bit operands while the comparison is for two's-complement ```<=```. We can infer that ```data_t``` must be ```int```.

## Solution from the book
- B. The suffix ```w``` and register identifiers indicate 16-bit operands while the comparison is for ```==```. We can infer that ```data_t``` must be either ```short or unsigned short```.