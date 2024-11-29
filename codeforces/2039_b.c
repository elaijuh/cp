// https://codeforces.com/contest/2039/problem/B
// CodeTON Round 9 (Div. 1 + Div. 2, Rated, Prizes!), B.Shohag Loves Strings
// #constructive #algorithms #greedy #implementation #strings

#include <stdio.h>

int main() {
	int T;
	char s[100001];
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int l = strlen(s);
		if (l == 1) puts("-1");
		else if (l == 2)
			if (s[0] != s[1]) puts("-1");
			else puts(s);
		else {
			int i = 0;
			for (; i < l - 2; i++) {
				if (s[i] == s[i + 1]) {
					printf("%c%c\n", s[i], s[i + 1]);
					break;
				} else if (s[i + 1] == s[i + 2]) {
					printf("%c%c\n", s[i + 1], s[i + 2]);
					break;
				} else if (s[i] != s[i + 2]) {
					printf("%c%c%c\n", s[i], s[i + 1], s[i + 2]);
					break;
				}
			}
			if (i == l - 2) puts("-1");
		}
	}
	return 0;
}
