#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countStudents(vector<int> &students, vector<int> &sandwiches)
	{
		int n = sandwiches.size();
		queue<int> q;
		for (int i = 0; i < n; ++i) q.push(students[i]);
		int topsw = 0, k = 0;
		while (!q.empty()) {
			int topst = q.front();
			q.pop();
			if (topst == sandwiches[topsw]) {
				topsw++;
				k = 0;
			}
			else {
				k++;
				q.push(topst);
			}
			if (k >= n - topsw)
				break;
		}
		return q.size();
	}
}
