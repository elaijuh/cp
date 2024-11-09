// https://atcoder.jp/contests/abc379/tasks/abc379_c
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
typedef struct {
	ll x, a;
} Cell;

int comp(const void* a, const void* b) { return ((Cell*)a)->x - ((Cell*)b)->x; }

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Cell c[m];
	for (int i = 0; i < m; i++) scanf("%lld", &c[i].x);
	for (int i = 0; i < m; i++) scanf("%lld", &c[i].a);
	qsort(c, m, sizeof(Cell), comp);
	ll ans = 0, g;

	if (c[0].x != 1) {
		printf("-1\n");
		return 0;
	}
	for (int i = 1; i < m; i++) {
		if (c[i].x - c[i - 1].x > c[i - 1].a) {
			printf("-1\n");
			return 0;
		}
		g = c[i].x - c[i - 1].x;
		ans += ((c[i - 1].a - 1) + (c[i - 1].a - g)) * g / 2;
		c[i].a += c[i - 1].a - g;
	}
	if (c[m - 1].a - 1 != n - c[m - 1].x) {
		printf("-1\n");
		return 0;
	}
	g = n - c[m - 1].x;
	ans += ((c[m - 1].a - 1) + (c[m - 1].a - g)) * g / 2;

	printf("%lld\n", ans);
	return 0;
}
