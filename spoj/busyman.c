// http://www.spoj.com/problems/BUSYMAN/ 
#include <stdio.h>
#include <stdlib.h>


int cmp (const void* e1, const void* e2) {
    const int* a = (const int*) e1;
    const int* b = (const int*) e2;

    if (a[1] < b[1])
        return -1;
    else if (a[1] == b[1])
        return a[0] - b[0] < 0 ? -1 : 1;
    else
        return 1;

    return 0;
}

int main() {
    int t, N, i, r, end, n[100000][2];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &N);
        for (i = 0; i < N; i++)
            scanf("%d %d", &n[i][0], &n[i][1]);

        qsort(n, N, sizeof(int[2]), cmp);

        end = -1, r = 0;
        for (i = 0; i < N; i++)
            if (n[i][0] >= end) {
                r++;
                end = n[i][1];
            }

        printf("%d\n", r);
    }

    return 0;
}