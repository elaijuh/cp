#include <bits/stdc++.h>

int main() {
    int n, m;
    long long ans = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &m);
        ans += m;
    }
    printf("%lld\n", ans);
    return 0;
}
