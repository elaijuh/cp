#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s)
	{
		stringstream ss(s);
		string token;
		while (ss >> token) {}
		return token.length();
	}
}
