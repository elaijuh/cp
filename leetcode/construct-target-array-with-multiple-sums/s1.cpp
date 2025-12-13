#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isPossible(vector<int> &target)
	{
		priority_queue<int> pq;
		long long sum = 0;
		for (int x : target) {
			pq.push(x);
			sum += x;
		}
		int n = target.size();
		while (pq.top() != 1) {
			int top = pq.top();
			pq.pop();
			sum -= top;
			if (top <= sum || sum < 1)
				return false;
			top %= sum;
			sum += top;
			pq.push(top ? top : sum);
		}
		return true;
	}
}
