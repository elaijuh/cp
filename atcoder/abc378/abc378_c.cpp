// https://atcoder.jp/contests/abc378/tasks/abc378_c
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, a;
	map<int, int> m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (m[a] == 0) {
			printf("%d ", -1);
		} else printf("%d ", m[a]);
		m[a] = i + 1;
	}

	return 0;
}
