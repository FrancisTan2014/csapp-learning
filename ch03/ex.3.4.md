#Practice Problem 3.4 (solution page 326)
Assume variables sp and dp are declared with types

```c
src_t *sp;
dest_t *dp;
```

where src_t and dest_t are data types declared with typedef. We wish to use the appropriate pair of data movement instructions to implement the operation

```c
*dp = (dest_t) *sp;
```

## My answer
Assume that ```*sp``` and ```*dp``` are stored in ```%rax``` and ```%rbx```, respectively. Then I'll give the answer below:
```
movq (%rax),%rcx
movq %rcx,(%rbx)
```