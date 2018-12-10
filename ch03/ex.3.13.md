#Practice Problem 3.13 (solution page 330)
The C code
```c
int comp(data_t a, data_t b) {
  return a COMP b;
}
```
shows a general comparison between arguments a and b, where data_t, the data type of the arguments, is defined (via typedef) to be one of the integer data types listed in Figure 3.1 and either signed or unsigned. The comparison COMP is defined via #define.

Suppose a is in some portion of %rdx while b is in some portion of %rsi. For each of the following instruction sequences, determine which data types data_t and which comparisons COMP could cause the compiler to generate this code. (There can be multiple correct answers; you should list them all.)

- A. 
```c
cmpl	%esi, %edi
setl	%al
```

- B.
```c
cmpw	%si, %di
setge	%al
```

- C.
```c
cmpb	%sil, %dil
setbe	%al
```

- D. 
```c
cmpq	%rsi, %rdi
setne	%a
```

## My answer
- A. The suffix `l` and register identifiers indicate 32-bit operands while the comparison is for two's-complement ```<```. We can infer that ```data_t``` must be ```int```.
- B. The suffix `w` and register identifiers indicate 16-bit operands while the comparison is for tow's-complement ```>=```. We can infer that ```data_t``` must be ```short```.
- C. The suffix ```b``` and register identifiers indicate 8-bit operands while the comparison is for unsigned ```<=```. We can infer that ```data_t``` must be ```unsigned char```.
- D. The suffix ```q``` and register identifiers indicate 64-bit operands while the comparison is for unsigned ```!=```. We can infer that ```data_t``` must be ```unsigned long``` **or some form of pointer(the added answer is from the book)**.