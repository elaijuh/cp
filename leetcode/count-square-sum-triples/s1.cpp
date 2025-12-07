#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countTriples(int n)
	{
		int ans = 0;
		for (int i = 1; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				double c = sqrt(i * i + j * j);
				if (c <= n && c == (int)c)
					ans += 2;
			}
		}
		return ans;
	}
}
