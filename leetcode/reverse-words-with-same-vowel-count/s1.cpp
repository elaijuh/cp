#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string reverseWords(string s)
	{
		auto count_vowel = [](string s) {
			int k = 0;
			for (char c : s)
				if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
					k++;
			return k;
		};

		stringstream ss(s);
		string token, ans;
		ss >> token;
		int n = count_vowel(token);
		ans += token;
		while (ss >> token) {
			if (count_vowel(token) == n) {
				reverse(token.begin(), token.end());
			}
			ans += " " + token;
		}
		return ans;
	}
};
