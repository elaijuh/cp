// http://www.spoj.com/problems/COINS/
#include <iostream>
#include <map>

using namespace std;

map <int, long long> h;

long long max(long long a, long long b) {
	return a > b ? a : b;
}

long long f(int n) {
	if (!n) return 0;
	long long r = h[n];
	if (!r) {
		r = max(n, f(n/2) + f(n/3) + f(n/4));
		h[n] = r;
	}
	return r;
}

int main() {
	int n;
	while (cin >> n)
		cout << f(n) << endl;

	return 0;
}