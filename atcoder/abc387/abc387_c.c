// https://atcoder.jp/contests/abc387/tasks/abc387_c
// #number

#include <stdio.h>
#include <string.h>

typedef long long ll;

ll cnt(ll n) {
	if (n < 10) return 0;

	char s[20];
	sprintf(s, "%lld", n);
	int slen = strlen(s);
	int n0 = s[0] - '0';

	// biggest snake number < n
	for (int i = 1; i < slen; i++) {
		if (s[i] - '0' >= n0) {
			for (int j = i; j < slen; j++) s[j] = s[0] - 1;
			break;
		}
	}

	// first digit == n0
	ll res = 0;
	for (int i = 1; i < slen; i++) {
		res = n0 * res + s[i] - '0';
	}
	res++;

	// first digit < n0
	int nt = n0 - 1;
	int idx = 1;

	while (idx < slen) {
		if (nt == 0) {
			nt = 9;
			idx++;
			continue;
		}
		ll d = 1;
		for (int i = idx; i < slen; i++) d *= nt;
		res += d;
		nt--;
	}

	return res;
}

int main() {
	ll l, r;
	scanf("%lld%lld", &l, &r);
	printf("%lld\n", cnt(r) - cnt(l - 1));
	return 0;
}
