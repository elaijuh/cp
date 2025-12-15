// https://atcoder.jp/contests/abc436/tasks/abc436_b

#include <bits/stdc++.h>
using namespace std;

void p(vector<vector<int>> &v)
{
	for (auto x : v) {
		for (auto y : x) cout << y << " ";
		cout << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n, 0));
	int r = 0, c = (n - 1) >> 1;
	int k = 1;
	v[r][c] = k;
	int count = n * n - 1;
	while (count--) {
		if (!v[(r - 1 + n) % n][(c + 1) % n]) {
			r = (r - 1 + n) % n;
			c = (c + 1) % n;
			v[r][c] = ++k;
		}
		else {
			r = (r + 1) % n;
			v[r][c] = ++k;
		}
	}
	p(v);
	return 0;
}
