#include <stdio.h> 
#include <math.h>

int tadd_ok(int x, int y);
int tadd_ok_frombook(int x, int y);
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
    if (x == 0 || y == 0) {
        return 1;
    } else if ((x < 0 && y > 0) || (x > 0 && y < 0)) {
        return 1;
    } else if (x > 0 && y > 0) {
        return x + y > 0;
    } else {
        return x + y < 0;
    }
}

int tadd_ok_frombook(int x, int y) {
    int sum = x + y;
    int neg_over = x < 0 && y < 0 && sum >= 0;
    int pos_over = x >= 0 && y >= 0 && sum < 0;
    return !neg_over && !pos_over;
}
