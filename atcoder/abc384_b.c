// https://atcoder.jp/contests/abc384/tasks/abc384_b

#include <stdio.h>

int main() {
	int n, r, d, a;
	scanf("%d %d", &n, &r);
	while (n--) {
		scanf("%d %d", &d, &a);
		if ((d == 1 && 1600 <= r && r <= 2799) ||
			(d == 2 && 1200 <= r && r <= 2399))
			r += a;
	}
	printf("%d\n", r);
	return 0;
}
