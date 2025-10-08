// https://atcoder.jp/contests/abc383/tasks/abc383_a

#include <stdio.h>

int main() {
	int n, t, v, tp = 0, ans = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &t, &v);
		ans -= t - tp;
		if (ans < 0) ans = 0;
		ans += v;
		tp = t;
	}
	printf("%d\n", ans);
	return 0;
}
