#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	long long removeZeros(long long n)
	{
		string s = to_string(n);
		erase(s, '0');
		return stoll(s);
	}
}
