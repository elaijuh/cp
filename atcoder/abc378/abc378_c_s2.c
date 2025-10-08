// https://atcoder.jp/contests/abc378/tasks/abc378_c
// #hash #map
#include <stdio.h>
#include <stdlib.h>

#define HASH_P 262139

struct Hash {
	int k, v;
	struct Hash* next;
}* h[HASH_P];

int hash(int k) { return k % HASH_P; }

struct Hash* put(int k, int v) {
	int hk = hash(k);
	struct Hash* p = h[hk];
	while (p != NULL) {
		if (p->k == k) break;
		p = p->next;
	}
	if (p == NULL) {
		p = (struct Hash*)malloc(sizeof(struct Hash));
		p->k = k;
		p->v = v;
		p->next = h[hk];
		h[hk] = p;
	} else p->v = v;
	return p;
}

int get(int k) {
	int hk = hash(k);
	struct Hash* p = h[hk];
	while (p != NULL) {
		if (p->k == k) break;
		p = p->next;
	}
	if (p == NULL) return -1;
	return p->v;
}

int main() {
	int n, k, x, ans;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		printf("%d ", get(x));
		put(x, i + 1);
	}
	return 0;
}
