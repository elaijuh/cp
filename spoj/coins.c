// http://www.spoj.com/problems/COINS/
#include <stdio.h>

long long h[30][19];

long long max(long long a, long long b) {
    return a > b ? a : b;
}

long long f(n, d2, d3) {
    if (!n) return 0;
    long long r = h[d2][d3];
    if (!r) {
        r = max(n, f(n / 2, d2 + 1, d3) + f(n / 3, d2, d3 + 1) + f(n / 4, d2 + 2, d3));
        h[d2][d3] = r;
    }

    return r;
}

int main() {
    int n, i, j;
    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < 30; i++)
            for (j = 0; j < 19; j++)
                h[i][j] = 0;

        printf("%lld\n", f(n, 0, 0));
    }

    return 0;
}