// https://atcoder.jp/contests/abc379/tasks/abc379_b
#include <stdio.h>

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	char s[n + 1];
	scanf("%s", s);
	int ans = 0;
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'O') t++;
		else t = 0;
		if (t == k) {
			t = 0;
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
