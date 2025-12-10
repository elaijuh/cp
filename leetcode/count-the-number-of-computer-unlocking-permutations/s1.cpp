#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	const int MOD = 1000'000'007;
	int fact(int n)
	{
		int f = 1;
		for (int i = 1; i <= n; ++i) f = ((1LL * f % MOD) * i % MOD) % MOD;
		return f;
	}

	int countPermutations(vector<int> &complexity)
	{
		int t = 0;
		for (int x : complexity)
			if (x > complexity[0])
				t++;
		if (t < complexity.size() - 1)
			return 0;
		return fact(t);
	}
};
