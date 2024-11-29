// https://atcoder.jp/contests/abc380/tasks/abc380_e
// #DSU

#include <stdio.h>

// DSU
int ds[500001];
int dssz[500001];
void make_set(int v) {
	ds[v] = v;
	dssz[v] = 1;
}
int find_set(int v) {
	if (v == ds[v]) return v;
	return ds[v] = find_set(ds[v]);
}
void union_set(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (a > b) {  // maintain left most index of disjoint set
			a = a ^ b;
			b = a ^ b;
			a = b ^ a;
		}
		ds[b] = a;
		dssz[a] += dssz[b];
	}
}

int main() {
	int n, q, x, c, qt;
	scanf("%d%d", &n, &q);
	int colors[n + 1], cells[n + 1];
	for (int i = 1; i <= n; i++) {
		colors[i] = 1;
		cells[i] = i;
		make_set(i);
	}
	while (q--) {
		scanf("%d", &qt);
		int l, sz;
		if (qt == 1) {
			scanf("%d%d", &x, &c);
			l = find_set(x);
			sz = dssz[l];
			colors[cells[l]] -= sz;
			cells[l] = c;
			colors[cells[l]] += sz;
			if (cells[find_set(l - 1)] == c) union_set(l - 1, l);
			if (cells[find_set(l + sz)] == c) union_set(l, l + sz);
		} else {
			scanf("%d", &c);
			printf("%d\n", colors[c]);
		}
	}

	return 0;
}
