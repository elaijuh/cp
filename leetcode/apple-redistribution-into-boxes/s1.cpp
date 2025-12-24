#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumBoxes(vector<int> &apple, vector<int> &capacity)
	{
		sort(capacity.begin(), capacity.end(), greater<int>());
		int m = 0, ans = 0;
		for (int &a : apple) m += a;
		for (int i = 0; i < capacity.size(); ++i) {
			m -= capacity[i];
			if (m <= 0) {
				ans = i;
				break;
			}
		}
		return ans + 1;
	}
}
