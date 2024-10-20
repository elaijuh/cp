// https://atcoder.jp/contests/abc376/tasks/abc376_b
#include "stdio.h"

int main() {
    int n, q, t;
    char h;
    int l = 1, r = 2, res = 0;
    scanf("%d %d", &n, &q);
    while (q--) {
        scanf(" %c %d", &h, &t);
        if (h == 'L') {
            if (t > l) {
                if (r > l && r < t)
                    res += n - (t - l);
                else
                    res += t - l;
            } else {
                if (r > t && r < l)
                    res += n - (l - t);
                else
                    res += l - t;
            }
            l = t;
        } else {
            if (t > r) {
                if (l > r && l < t)
                    res += n - (t - r);
                else
                    res += t - r;
            } else {
                if (l > t && l < r)
                    res += n - (r - t);
                else
                    res += r - t;
            }
            r = t;
        }
    }
    printf("%d\n", res);
    return 0;
}
