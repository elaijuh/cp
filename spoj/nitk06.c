// http://www.spoj.com/problems/NITK06/
#include <stdio.h>

int main() {
    int t, N, n[10000], i;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &N);
        for (i = 0; i < N; i++)
            scanf("%d", &n[i]);
        for (i = 0; i < N - 1; i++) {
            if (n[i] > n[i+1])
                break;
            n[i+1] -= n[i];
        }
        if (i == N - 1 && n[i] == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}