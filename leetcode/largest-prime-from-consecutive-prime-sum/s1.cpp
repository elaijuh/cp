#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int largestPrime(int n)
	{
		// Sieve of Eratosthenes
		vector<bool> is_prime(n + 1, true);
		is_prime[0] = false;
		is_prime[1] = false;
		for (int p = 2; p * p <= n; ++p) {
			if (is_prime[p]) {
				for (int i = p * p; i <= n; i += p) is_prime[i] = false;
			}
		}
		long long sum = 0;
		int ans = 0;
		for (int i = 0; i <= n; ++i) {
			if (is_prime[i]) {
				sum += i;
				if (sum <= n && is_prime[sum])
					ans = sum;
			}
		}
		return ans;
	}
};
