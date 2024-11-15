// http://codeforces.com/contest/527/problem/A
#include <stdio.h>

int main() {
	long long int a, b, t, n = 0;
	scanf("%lld %lld", &a, &b);
	while (b != 0) {
		n += a / b;
		t = a;
		a = b;
		b = t % b;
	}
	printf("%lld\n", n);

	return 0;
}