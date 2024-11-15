// https://codeforces.com/contest/2027/problem/A
// Codeforces Round 982 (Div. 2), A.Rectangle Arrangement
// #geometry #implementation #math

#include <stdio.h>

int main() {
	int T;
	int n, mw, mh, ans;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int s[n][2];
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &s[i][0], &s[i][1]);
		}
		mw = s[0][0];
		mh = s[0][1];
		ans = (s[0][0] + s[0][1]) * 2;
		for (int i = 1; i < n; i++) {
			if (s[i][0] > mw) {
				ans += (s[i][0] - mw) * 2;
				mw = s[i][0];
			}
			if (s[i][1] > mh) {
				ans += (s[i][1] - mh) * 2;
				mh = s[i][1];
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
