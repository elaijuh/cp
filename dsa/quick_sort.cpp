// https://wandbox.org/permlink/wo8MCpUHOHxXA518
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &a, int l, int h)
{
	int p = h;
	int firsthigh = l;
	for (int i = l; i < h; i++) {
		if (a[i] < a[p]) {
			swap(a[i], a[firsthigh]);
			firsthigh++;
		}
	}
	swap(a[p], a[firsthigh]);
	return firsthigh;
}

void quick_sort(vector<int> &a, int l, int h)
{
	if (l < h) {
		int p = partition(a, l, h);
		quick_sort(a, l, p - 1);
		quick_sort(a, p + 1, h);
	}
}

int main()
{
	vector<int> a = {2, 4, 3, 10, 6, 11, 4};
	quick_sort(a, 0, a.size() - 1);
	for (int &x : a) cout << x << " ";
	return 0;
}
