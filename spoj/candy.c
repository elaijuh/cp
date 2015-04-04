// http://www.spoj.com/problems/CANDY/
#include <stdio.h>

int main() {
    int n, i, s, c[10000], r;
    while (scanf("%d", &n)) {
        if (n == -1) break;
        for (i = 0, s = 0; i < n; i++) {
            scanf("%d", &c[i]);
            s += c[i];
        }
        if (s % n)
            printf("-1\n");
        else {
            s /= n;
            for (i = 0, r = 0; i < n; i++)
                r += (s - c[i] > 0) ? s - c[i] : 0;
            printf("%d\n", r);
        }

    }

    return 0;
}