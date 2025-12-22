#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b)
	{
		int i = a.size() - 1, j = b.size() - 1, carry = false;
		string ans;
		while (i >= 0 || j >= 0 || carry) {
			int sum = carry;
			if (i >= 0) sum += (a[i--] - '0');
			if (j >= 0) sum += (b[j--] - '0');
			carry = sum / 2;
			sum %= 2;
			ans = to_string(sum) + ans;
		}
		if (carry) ans = "1" + ans;
		return ans;
	}
};
