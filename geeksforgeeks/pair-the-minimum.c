/*
 * Problem: https://practice.geeksforgeeks.org/problems/pair-the-minimum/0
 * Date: 2018-04-28
 */

#include <stdio.h>

void swap(int v[], int i, int j) {
	int tmp;
	tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

void qsort(int v[], int left, int right) {
	int i, last;
	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if (v[i] < v[left])
			swap(v, ++last, i);
	}
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

int main(void) {
    int t, n, a[300];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < 2*n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, 0, 2*n-1);
        for (int i = 0; i < n; i++) {
            printf("(%d,%d)", a[i], a[2*n-i-1]);
        }
        printf("\n");
    }
}
