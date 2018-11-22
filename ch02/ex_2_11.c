#include <stdio.h>

#define LEN(a) (sizeof(a) / sizeof(a[0]))

void inplace_swap(int *x, int *y);
void print_array(int *a, int cnt);
void reverse(int *a, int cnt);

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6 };
    int cnt = LEN(array);
    printf("before reverse, the elements are: ");
    print_array(array, cnt);
    reverse(array, cnt);
    printf("after reverse, the elements are: ");
    print_array(array, cnt);
    return 0;
}

void inplace_swap(int *x, int *y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void print_array(int *a, int cnt) {
    int i;
    for (i = 0; i < cnt; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void reverse(int *a, int cnt) {
    int first, last;
    for (first = 0, last = cnt - 1; first < last; first++, last--) {
        inplace_swap(&a[first], &a[last]);
    }
}
