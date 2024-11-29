// https://codeforces.com/contest/2039/problem/A
// CodeTON Round 9 (Div. 1 + Div. 2, Rated, Prizes!), A.Shohag Loves Mod
// #constructive #algorithms #number #theory

#include <stdio.h>

int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			if (i != 0) printf(" ");
			printf("%d", i * 2 + 1);
		}
		puts("");
	}
	return 0;
}
