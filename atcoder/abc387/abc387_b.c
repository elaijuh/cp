// https://atcoder.jp/contests/abc387/tasks/abc387_b

#include <stdio.h>

int main() {
	int x;
	int s = 0;
	scanf("%d", &x);
	for (int i = 1; i <= 9; i++) {
		s += (i + 9 * i) * 9 / 2;
		if (x >= i && x <= 9 * i && x % i == 0) s -= x;
	}
	printf("%d\n", s);
	return 0;
}
