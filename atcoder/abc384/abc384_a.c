// https://atcoder.jp/contests/abc384/tasks/abc384_a

#include <stdio.h>

int main() {
	int n;
	char s[100], c1, c2;
	scanf("%d %c %c", &n, &c1, &c2);
	scanf("%s", s);
	for (int i = 0; i < n; i++)
		if (s[i] != c1) s[i] = c2;
	printf("%s\n", s);
	return 0;
}
