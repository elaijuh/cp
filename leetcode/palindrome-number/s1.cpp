#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	typedef long long ll;
	bool isPalindrome(int x)
	{
		if (x < 0)
			return false;
		ll y = x, z = 0;
		while (y) {
			z = z * 10 + y % 10;
			y /= 10;
		}
		return x == z;
	}
}
