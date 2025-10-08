// https://atcoder.jp/contests/abc378/tasks/abc378_b
#include "stdio.h"

int main() {
    int n, q, t, d;
    scanf("%d", &n);
    int a[n][2];
    int ans;
    for (int i = 0; i < n; i++) scanf("%d %d", &a[i][0], &a[i][1]);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &t, &d);
        ans = d / a[t - 1][0] * a[t - 1][0] + a[t - 1][1];
        if (ans < d) ans += a[t - 1][0];
        printf("%d\n", ans);
    }

    return 0;
}
