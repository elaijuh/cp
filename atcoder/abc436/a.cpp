// https://atcoder.jp/contests/abc436/tasks/abc436_a

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	string s;
	cin >> n >> s;
	string prefix(n - s.size(), 'o');
	cout << prefix << s << "\n";
	return 0;
}
