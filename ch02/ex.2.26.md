#Practice Problem 2.26 (solution page 151)
You are given the assignment of writing a function that determines whether one string is longer than another. You decide to make use of the string library function strlen having the following declaration:

```c
/* Prototype for library function strlen */  
size_t strlen(const char *s);
```

Here is your first attempt at the function:

```c
/* Determine whether string s is longer than string t */
/* WARNING: This function is buggy */
int strlonger(char *s, char *t) {
	return strlen(s) - strlen(t) > 0;
}
```

When you test this on some sample data, things do not seem to work quite right. You investigate further and determine that, when compiled as a 32-bit program, data type size_t is defined (via typedef) in header file stdio.h to be unsigned.

A. For what cases will this function produce an incorrect result?

B. Explain how this incorrect result comes about.

C. Show how to fix the code so that it will work reliably.

## Answer
A. For the cases of s's length is less than t's length.

B. According to the problem, function ```strlen``` returns an unsigined. Thus, ```strlen(s) - strlen(t)``` will always more than 0 no matter which string's length is longer.

C. Change the code of testing the length in function strlonger to ```strlen(s) > strlen(t)```.