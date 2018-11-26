#include <stdio.h>
#include <string.h>

int strlonger(char *s, char *t);
int strlonger_fixed(char *s, char *t);

int main() {
    char *s1 = "hello";
    char *s2 = "hello world";
    int result = strlonger(s1, s2);
    printf("result of strlonger is: %d\n", result);
    result = strlonger_fixed(s1, s2);
    printf("result of strlonger_fixed is: %d\n", result);
}

/* WARNING: This function is buggy */
int strlonger(char *s, char *t) {
	return strlen(s) - strlen(t) > 0;
}

int strlonger_fixed(char *s, char *t) {
	return strlen(s) > strlen(t);
}