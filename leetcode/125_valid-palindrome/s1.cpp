#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isPalindrome(string s)
	{
		int n = s.size();
		int l = 0, r = n - 1;
		while (l <= r) {
			if (!isalnum(s[l])) {
				l++;
				continue;
			}
			else if (s[l] >= 'A' && s[l] <= 'Z')
				s[l] += 32;
			if (!isalnum(s[r])) {
				r--;
				continue;
			}
			else if (s[r] >= 'A' && s[r] <= 'Z')
				s[r] += 32;
			if (s[l] == s[r]) {
				l++;
				r--;
				continue;
			}
			else
				break;
		}
		if (l >= r)
			return true;
		return false;
	}
}
