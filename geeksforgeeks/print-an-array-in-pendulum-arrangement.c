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
    int t, n, i, k, a[100];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, 0, n-1);
        if (n%2 == 0) {
            k=n-2;
        } else {
            k=n-1;
        }
        while (k>=0) {
            printf("%d ", a[k]);
            k-=2;
        }
        k = 1;
        while (k<n) {
            printf("%d ", a[k]);
            k+=2;
        }
        printf("\n");
    }
}
