// https://codeforces.com/contest/2031/problem/C
// Codeforces Round 987 (Div. 2), C.Penchick and BBQ Buns
// #brute #force #constructive #algorithms #math #number #theory

#include <stdio.h>

int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int a[n];
		if (n % 2 == 0) {
			for (int i = 1; i <= n / 2; i++) printf("%d %d ", i, i);
			puts("");
		} else if (n < 27) puts("-1");
		else {
			printf("1 2 3 3 4 4 5 5 6 1 7 7 6 8 8 9 9 10 10 11 11 12 12 13 13 1 2");
			for (int i = 14; i <= n / 2; i++) printf(" %d %d", i, i);
			puts("");
		}
	}
	return 0;
}
