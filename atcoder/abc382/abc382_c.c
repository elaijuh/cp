// https://atcoder.jp/contests/abc382/tasks/abc382_c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, i;
} S;

int comp(const void* a, const void* b) {
	if (((S*)a)->x > ((S*)b)->x) return 1;
	else if (((S*)a)->x == ((S*)b)->x) return ((S*)a)->i - ((S*)b)->i;
	else return 0;
}

int sol1() {
	int n, m;
	S a[200000], b[200000];
	int ans[200001];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		a[i].i = i + 1;
		scanf("%d", &a[i].x);
	}
	for (int i = 0; i < m; i++) {
		b[i].i = i + 1;
		scanf("%d", &b[i].x);
	}
	qsort(a, n, sizeof(S), comp);
	qsort(b, m, sizeof(S), comp);
	int min, k, i = 0;
	for (int j = 0; j < m; j++) {
		if (b[j].x < a[i].x) ans[b[j].i] = -1;
		else {
			min = a[i].i;
			while (b[j].x >= a[i].x && i < n) {
				if (a[i].i < min) {
					min = a[i].i;
				}
				i++;
			}
			a[--i].i = min;
			ans[b[j].i] = min;
		}
	}
	for (int j = 1; j <= m; j++) printf("%d\n", ans[j]);

	return 0;
}

int sol2() {
	int n, m, t;
	int a[200001], b1[200001], b2[200001], maxa = 0, maxb = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		if (maxa < t) maxa = t;
		if (a[t] == 0) a[t] = i + 1;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &t);
		if (maxb < t) maxb = t;
		if (b1[t] == 0) b1[t] = i + 1;
		b2[i + 1] = t;
	}
	int i = 1, j = 1, min = 0;
	while (i <= maxa && j <= maxb) {
		if (b1[j] == 0) {
			j++;
			continue;
		}
		if (a[i] == 0) {
			i++;
			continue;
		}
		if (j < i) b1[j++] = -1;
		else {
			min = a[i];
			while (j >= i && i <= maxa) {
				if (a[i] != 0 && a[i] < min) min = a[i];
				i++;
			}
			a[--i] = min;
			b1[j++] = min;
		}
	}
	for (int j = 1; j <= m; j++) printf("%d\n", b1[b2[j]]);
	return 0;
}

int main() {
	// sol1();
	sol2();
	return 0;
}
