// https://atcoder.jp/contests/abc426/tasks/abc426_a

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	unordered_map<string, int> u = {{"Ocelot", 0}, {"Serval", 1}, {"Lynx", 2}};
	string x, y;
	cin >> x >> y;
	if (u[x] >= u[y]) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
