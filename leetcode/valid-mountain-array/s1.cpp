#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool validMountainArray(vector<int> &arr)
	{
		int n = arr.size();
		if (n == 1)
			return false;
		int f = 0;
		for (int i = 1; i < n; ++i) {
			if (arr[i] == arr[i - 1])
				return false;
			if (arr[i] > arr[i - 1]) {
				if (f == -1)
					return false;
				f = 1;
			}
			if (arr[i] < arr[i - 1]) {
				if (f == 0)
					return false;
				else
					f = -1;
			}
		}
		return f == -1;
	}
}
