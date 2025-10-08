// https://atcoder.jp/contests/abc276/tasks/abc376_a
#include "stdio.h"
#include "stdlib.h"

int main() {
    int n, c;
    int* t;
    int res = 1;
    scanf("%d %d", &n, &c);
    t = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &t[i]);
    for (int i = 1; i < n; i++) {
        if (t[i] - t[i - 1] >= c)
            res++;
        else
            t[i] = t[i - 1];
    }
    printf("%d\n", res);

    free(t);
    return 0;
}
