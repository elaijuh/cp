// quick sort
// worst case 26^2 < 1000, should pass testset1
// average case 26log26 > 100, may or may not pass testset2. Better add memory footprint.
// average case 5log5 > 7, most likely cannot pass all testset3, must handle separately.
//
#include <bits/stdc++.h>
using namespace std;

int compare(const void *a, const void *b)
{
	const char *x = (char *)a;
	const char *y = (char *)b;
	cout << "? " << *x << " " << *y << endl;
	char ans;
	cin >> ans;
	if (ans == '>')
		return 1;
	else
		return -1;
	return 0;
}

int main()
{
	int n, q, i;
	cin >> n >> q;
	char s[n + 1];
	for (i = 0; i < n; i++)
		s[i] = 'A' + i;
	s[i] = '\0';

	// testset1, testset2
	if (n == 26) {
		qsort(s, n, sizeof(char), compare);
		cout << "! " << s << endl;
		return 0;
	}
	// testset3
	if (compare(&s[0], &s[1]) == 1)
		swap(s[0], s[1]);
	if (compare(&s[2], &s[3]) == 1)
		swap(s[2], s[3]);
	if (compare(&s[0], &s[2]) == 1) {
		swap(s[0], s[2]);
		swap(s[1], s[3]);
	}
	if (compare(&s[2], &s[4]) == 1) {
		if (compare(&s[0], &s[4]) == 1) {
			swap(s[0], s[4]);
			swap(s[1], s[4]);
			swap(s[2], s[4]);
			swap(s[3], s[4]);
			if (compare(&s[2], &s[3]) == 1)
				swap(s[2], s[3]);
			if (compare(&s[3], &s[4]) == 1)
				swap(s[3], s[4]);
		} else {
			swap(s[2], s[4]);
			swap(s[3], s[4]);
			if (compare(&s[1], &s[3]) == 1) {
				swap(s[1], s[2]);
				swap(s[2], s[3]);
				if (compare(&s[3], &s[4]) == 1)
					swap(s[3], s[4]);
			} else {
				if (compare(&s[1], &s[2]) == 1)
					swap(s[1], s[2]);
			}
		}
	} else {
		if (compare(&s[3], &s[4]) == 1)
			swap(s[3], s[4]);
		if (compare(&s[1], &s[3]) == 1) {
			swap(s[1], s[2]);
			swap(s[2], s[3]);
			if (compare(&s[3], &s[4]) == 1)
				swap(s[3], s[4]);
		} else {
			if (compare(&s[1], &s[2]) == 1)
				swap(s[1], s[2]);
		}
	}
	cout << "! " << s << endl;
	return 0;
}
