// http://www.spoj.com/problems/CHOCOLA/

#include <stdio.h>
#include <stdlib.h>

int cmp (const void* e1, const void* e2) {
    const int* a = (const int*) e1;
    const int* b = (const int*) e2;

    if (a[0] < b[0])
        return 1;
    else if (a[0] > b[0])
        return -1; 

    return 0;
}

int main() {
    int t, m, n, a[2000][2], x, y, r, i;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &m, &n);
        for (i = 0; i < m + n - 2; i++) {
            scanf("%d", &a[i][0]);
            a[i][1] = i < m - 1 ? 0 : 1;
        }
        qsort(a, m + n - 2, sizeof(int[2]), cmp);
        r = 0, x = 1, y = 1;
        for (i = 0; i < m + n - 2; i++)
            if (a[i][1]) {
                r += x * a[i][0];
                y++;
            } else {
                r += y * a[i][0];
                x++;
            }
        printf("%d\n", r);
    }
    return 0;
}