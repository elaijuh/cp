// https://codeforces.com/contest/2039/problem/C1
// CodeTON Round 9 (Div. 1 + Div. 2, Rated, Prizes!), C1.Shohag Loves XOR (Easy Version)
// #bitmasks #brute #force #math #number #theory

#include <stdio.h>

typedef long long ll;

int main() {
	int T;
	ll x, m, ans;
	scanf("%d", &T);
	while (T--) {
		ans = 0;
		scanf("%lld %lld", &x, &m);
		for (ll y = 1; y <= m && y < x << 1; y++) {
			if (x == y) continue;
			if (x % (x ^ y) == 0 || y % (x ^ y) == 0) ans++;
		}
		printf("%lld\n", ans);
	}

	return 0;
}
