// https://qoj.ac/submission/686171
// 452ms
#include "stdio.h"

int main() {
    int n = 100000000;
    for (int i = 0; i < 10000000; ++i) {
        printf("%d\n", n);
    }
    return 0;
}
