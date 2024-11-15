// https://codeforces.com/contest/2031/problem/A
// Codeforces Round 987 (Div. 2), A.Penchick and Modern Monument
// #greedy #sortings

#include <stdio.h>

int main() {
	int T, n, h, hp, t, max;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		hp = 0;
		t = 0;
		max = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &h);
			if (h != hp) {
				t = 1;
				hp = h;
			} else t++;
			if (t > max) max = t;
		}
		printf("%d\n", n - max);
	}
	return 0;
}
