// https://atcoder.jp/contests/abc382/tasks/abc382_b
#include <stdio.h>

int main() {
	char s[101];
	int n, d, ans;
	scanf("%d %d", &n, &d);
	scanf("%s", s);
	ans = 0;
	for (int i = n - 1; i >= 0 && d > 0; i--)
		if (s[i] == '@') {
			s[i] = '.';
			d--;
		}
	printf("%s\n", s);
	return 0;
}
