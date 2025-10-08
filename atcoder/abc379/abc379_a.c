// https://atcoder.jp/contests/abc379/tasks/abc379_a
#include <stdio.h>

int main() {
	char s[4];
	scanf("%s", &s);
	printf("%c%c%c ", s[1], s[2], s[0]);
	printf("%c%c%c\n", s[2], s[0], s[1]);
	return 0;
}
