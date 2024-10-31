// https://atcoder.jp/contests/abc377/tasks/abc377_d
#include "stdio.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, m, l, r;
    scanf("%d %d", &n, &m);
    int d[m + 1];
    for (int i = 0; i <= m; i++) d[i] = 1;
    while (n--) {
        scanf("%d %d", &l, &r);
        d[r] = max(d[r], l + 1);
    }
    long ans = 0;
    for (int i = 1; i <= m; i++) {
        d[i] = max(d[i], d[i - 1]);
        ans += i - d[i] + 1;
    }
    printf("%ld\n", ans);
    return 0;
}
