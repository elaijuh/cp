// https://qoj.ac/submission/696858
// 63ms

#include "stdio.h"
#define T 110000001

char p[T], *p1;
int fastread() {
    char c;
    int r = 0;
    do {
        c = *p1++;
    } while (c < 48 || c > 57);
    do {
        r = r * 10 + c - 48;
        c = *p1++;
    } while (c >= 48 && c <= 57);
    return r;
}

int main() {
    p1 = p;
    fread(p, 1, T, stdin);
    int n = fastread();
    long long ans = 0;
    while (n--) {
        ans += fastread();
    }
    printf("%lld\n", ans);
    return 0;
}
