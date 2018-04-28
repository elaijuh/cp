/*
 * Problem: https://practice.geeksforgeeks.org/problems/min-coin/0
 * Category: Medium
 * Tag: 
 * Date: 2018-04-29
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    int t, v, n, c[100];
    int count[100001]; /* count[i] is the minimum number of coins to change for value i */
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &v);
        for (int i=0; i<n; i++) {
            scanf("%d", &c[i]);
        }
        memset(count, 0, sizeof(count));
        for (int i=1; i<=v; i++) {
            int min = 100001;
            for (int j=0; j<n; j++) {
                if (i >= c[j]) {
                    /*
                     * i == c[j] is the initial state, means 0 value needs 0 coins
                     * count[i-c[j]] > 0 means before adding j coin,
                     * the is an answer for value i-c[j]
                     */
                    if (count[i-c[j]] + 1 < min && (i == c[j] || count[i-c[j]])) {
                        min = count[i-c[j]] + 1;
                    }
                }
            }
            if (min < 100001) {
                count[i] = min;
            }
        }
        if (count[v]) {
            printf("%d\n", count[v]);
        } else {
            printf("-1\n");
        }
    }
}
