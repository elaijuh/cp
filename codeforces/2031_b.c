// https://codeforces.com/contest/2031/problem/B
// Codeforces Round 987 (Div. 2), B.Penchick and Satay Sticks
// #greedy #sortings

#include <stdio.h>

int main() {
	int T, n, t, i;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int p[n];
		for (i = 0; i < n; i++) scanf("%d", &p[i]);
		for (i = 0; i < n - 1; i++) {
			if (p[i] > p[i + 1] && p[i] - 1 == p[i + 1]) {
				p[i] = p[i] ^ p[i + 1];
				p[i + 1] = p[i] ^ p[i + 1];
				p[i] = p[i + 1] ^ p[i];
			}
			if (p[i] != i + 1) {
				break;
			}
		}
		if (i != n - 1 || p[i] != n) {
			printf("NO\n");
		} else printf("YES\n");
	}
	return 0;
}
