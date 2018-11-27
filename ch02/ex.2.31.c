#include <stdio.h>

int tadd_ok(int x, int y);
void print(int x, int y, int ok);

int main() {
    // case 1
    int x = 0x80000000;
    int y = 0x80000000;
    int ok = tadd_ok(x, y);
    print(x, y, ok);

    // case 2
    x = -1;
    y = -2;
    ok = tadd_ok(x, y);
    print(x, y, ok);
    
    // case 3
    x = 3;
    y = 4;
    ok = tadd_ok(x, y);
    print(x, y, ok);

    x = 0x7fffffff;
    y = 0x7fffffff;
    ok = tadd_ok(x, y);
    print(x, y, ok);

    return 0;
}

void print(int x, int y, int ok) {
    printf("with arguments x(%d) and y(%d), the result of tadd_ok is: %d\n", x, y, ok);
}

int tadd_ok(int x, int y) {
    int sum = x + y;
    printf("x=%d, y=%d\nsum=%d, sum-x=%d, sum-y=%d\n", x, y, sum, sum - x, sum - y);
    return (sum - x == y) && (sum - y == x);
}