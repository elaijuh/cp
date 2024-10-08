// https://atcoder.jp/contests/abc373/tasks/abc373_c
#include "limits.h"
#include "stdio.h"

int main() {
    int n, m;
    scanf("%d", &n);

    int a = INT_MIN, b = INT_MIN;
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        if (m > a) a = m;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        if (m > b) b = m;
    }
    printf("%d\n", a + b);
    return 0;
}
