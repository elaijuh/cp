// https://wandbox.org/permlink/tWpHz6rsvzDVxEwx
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &a, int l, int m, int h)
{
	vector<int> aux(h - l + 1);
	int k = 0, i = l, j = m + 1;
	while (i <= m && j <= h) {
		if (a[i] < a[j]) {
			aux[k++] = a[i++];
		}
		else {
			aux[k++] = a[j++];
		}
	}

	while (i <= m) aux[k++] = a[i++];
	while (j <= h) aux[k++] = a[j++];

	cout << "aux: ";
	for (int &x : aux) cout << x << " ";
	cout << "\n";

	for (int i = l; i <= h; i++) a[i] = aux[i - l];

	cout << "a: ";
	for (int &x : a) cout << x << " ";
	cout << "\n";
}

void merge_sort(vector<int> &a, int l, int h)
{
	int m;
	if (l < h) {
		m = (l + h) / 2;
		merge_sort(a, l, m);
		merge_sort(a, m + 1, h);
		merge(a, l, m, h);
	}
}

int main()
{
	vector<int> a{6, 4, 12, 5, 1, 9, 21, 3};
	merge_sort(a, 0, a.size() - 1);
	return 0;
}
