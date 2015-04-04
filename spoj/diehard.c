// http://www.spoj.com/problems/DIEHARD/

#include <stdio.h>

int main() {
    int t, h, a, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &h, &a);
        h += 3;
        a += 2;
        c = 1;
        while (1) {
            if (h <= 0 || a <= 0)
                break;
            if (h > 5 && a > 10) {
                h -= 2;
                a -= 8;
                c += 2;
            } else if (h > 20) {
                h -= 17;
                a += 7;
                c += 2;
            } else {
                printf("%d\n", c);
                break;
            }
        }
    }

    return 0;
}