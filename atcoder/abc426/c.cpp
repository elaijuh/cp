// https://atcoder.jp/contests/abc426/tasks/abc426_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1, 1);
	int x, y, min = 1;
	while (q--) {
		cin >> x >> y;
		int res = 0;
		while (min <= x) {
			res += a[min];
			a[y] += a[min];
			min++;
		}
		cout << res << '\n';
	}
	return 0;
}
