#include <stdio.h>
#include <limits.h>
#include <time.h>

int main() {
    time_t start = clock();
    for (int i = 1; i <= 100000000; i++) {
        if (i != ((int)(double)i)) {
            printf("%d, %d\n", i, (int)(double)i);
        }
    }
    time_t end = clock();
    printf("%d\n", end - start);
}