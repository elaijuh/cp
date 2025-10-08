// https://atcoder.jp/contests/abc426/tasks/abc426_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	if (s[0] == s[1]) cout << s[s.length() - 1] << '\n';
	else cout << s[0] << '\n';
	return 0;
}
