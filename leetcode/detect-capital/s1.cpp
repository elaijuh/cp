#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool detectCapitalUse(string word)
	{
		bool first = word[0] >= 'A' && word[0] <= 'Z';
		int n_cap = 0;
		for (int i = 1; i < word.size(); ++i)
			if (word[i] >= 'A' && word[i] <= 'Z')
				n_cap++;
		if (n_cap == 0 || n_cap == word.size())
			return true;
		if (first && n_cap == word.size() - 1)
			return true;
		return false;
	}
}
