// https://atcoder.jp/contests/abc382/tasks/abc382_a

#include <stdio.h>

int main() {
	char s[101];
	int n, d, ans;
	scanf("%d %d", &n, &d);
	scanf("%s", s);
	ans = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == '.') ans++;
	ans += d;
	printf("%d\n", ans);
	return 0;
}
