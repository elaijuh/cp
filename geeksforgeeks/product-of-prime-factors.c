/* https://practice.geeksforgeeks.org/problems/product-of-prime-factors/0/ */

#include <stdio.h>
#include <string.h>

void euler_sieve(int n, int prime[]) {
    int i, j, k = 0;
    int flag[100000];
    memset(flag, 0, sizeof(flag));
    for (i = 2; i < n; i++) {
        if (!flag[i]) {
            prime[k++] = i;
        }
        for (j = 0; i * prime[j] <= n; j++) {
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }

    }
}

int main(void) {
    int prime[10000];
    memset(prime, 0, sizeof(prime));
    euler_sieve(100000, prime);

    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int p = 1;
        for (int i = 0; prime[i] && i < 10000; i++) {
            if (n % prime[i] == 0) {
                p *= prime[i];
            }
        }
        printf("%d\n", p);

    }
}

