#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countCollisions(string directions)
	{
		int ans = 0;
		stack<char> st;
		for (char c : directions) {
			if (c == 'R')
				st.push(c);
			else {
				while (!st.empty()) {
					char top = st.top();
					if (top == 'S' && c == 'L') {
						ans++;
						break;
					}
					if (top == 'S' && c == 'S')
						break;
					if (top == 'R' && c == 'L') {
						ans += 2;
						c = 'S';
						st.pop();
						continue;
					}
					if (top == 'R' && c == 'S') {
						ans++;
						st.pop();
						continue;
					}
				}
				if (c == 'S')
					st.push(c);
			}
		}
		return ans;
	}
};
