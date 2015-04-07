// http://www.spoj.com/problems/AMBM/

#include <stdio.h>

int main() {
    int t, k, a[51], i, j;
    long long n, b[51];
    scanf("%d", &t);
    while (t--) {
        scanf("%lld %d", &n, &k);
        for (i = 1; i <= k; scanf("%d", &a[i++]));
        for (i = 1, b[0] = 0; i <= k; i++)
            b[i] = a[i] + 2 * b[i-1];
        for (i = k, j = 0; i >= 1; i--)
            if (n >= b[i]) {
                n -= b[i];
                a[j++] = i;
            }
        if (n != 0)
            printf("-1\n");
        else {
            for (--j; j > 0; j--)
                printf("%d ", a[j]);
            printf("%d\n", a[j]);
        }
    }
    return 0;
}