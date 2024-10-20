// https://atcoder.jp/contests/abc376/tasks/abc376_c
#include "limits.h"
#include "stdio.h"
#include "stdlib.h"

int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int main() {
    int n;
    int* a;
    int* b;
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    b = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) scanf("%d", &b[i]);
    b[0] = 0;
    qsort(a, n, sizeof(int), cmp);
    qsort(b, n, sizeof(int), cmp);
    b[0] = INT_MAX;
    int i = n - 1, j = n - 1, k = 0;
    while (i >= 0) {
        if (a[i] > b[j]) {
            j++;
            k = i;
        }
        i--;
        j--;
    }

    if (j > 0)
        printf("-1\n");
    else
        printf("%d\n", a[k]);

    free(a);
    free(b);

    return 0;
}
