#include <stdio.h>

int uadd_ok(unsigned x, unsigned y);

int main() {
    unsigned x = 0xffffffff;
    unsigned y = 1;
    int addOk = uadd_ok(x, y);
    printf("with arguments %u and %u, the result of uadd_ok is: %d\n", x, y, addOk);

    x = 0xffff0000;
    y = 0x0000ffff;
    addOk = uadd_ok(x, y);
    printf("with arguments %u and %u, the result of uadd_ok is: %d", x, y, addOk);
    return 0;
}

int uadd_ok(unsigned x, unsigned y) {
    return x + y >= x; 
}