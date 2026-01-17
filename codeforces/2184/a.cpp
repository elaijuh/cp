// https://codeforces.com/contest/2184/problem/A
// name: Codeforces Round 1072 (Div. 3), A.Social Experiment
// raiting:
// tags: #math

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << (n <= 3 ? n : n % 2) << "\n";
	}
	return 0;
}
