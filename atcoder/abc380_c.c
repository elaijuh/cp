// https://atcoder.jp/contests/abc380/tasks/abc380_c
#include <stdio.h>

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	char s[n + 1];
	scanf("%s", s);
	int ki = 0, l = 0, r = 0, l1 = -1, l2 = -1, r1 = -1, r2 = -1;
	for (int i = 1; i < n; i++) {
		if (s[i] == '0') {
			if (s[i - 1] == '1') {
				ki++;
				if (ki == k - 1) {
					l1 = l;
					r1 = r;
				} else if (ki == k) {
					l2 = l;
					r2 = r;
					break;
				}
			}
		} else {
			if (s[i - 1] == '0') l = i;
			r = i;
		}
	}
	if (l2 == -1) l2 = l;
	if (r2 == -1) r2 = r;

	for (int i = 0; i <= r1; i++) putchar(s[i]);
	for (int i = l2; i <= r2; i++) putchar('1');
	for (int i = r1 + 1; i <= l2 - 1; i++) putchar('0');
	for (int i = r2 + 1; i < n; i++) putchar(s[i]);
	puts("");

	return 0;
}
