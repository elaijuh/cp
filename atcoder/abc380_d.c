// https://atcoder.jp/contests/abc380/tasks/abc380_d
// #bits #binary
#include <stdio.h>
#include <string.h>

typedef unsigned long long llu;

char flip(char c) {
	if (c >= 'a' && c <= 'z') return c - 'a' + 'A';
	else return c - 'A' + 'a';
}

llu count_bits(llu a) {
	llu count = 0;
	while (a) {
		count += a & 1;
		a >>= 1;
	}
	return count;
}

int main() {
	char s[200001];
	int q;
	llu k;
	scanf("%s", s);
	int l = strlen(s);
	scanf("%d", &q);
	int d;
	llu m;
	for (int i = 0; i < q; i++) {
		if (i) putchar(' ');
		scanf(" %llu", &k);
		m = (k - 1) / l;
		d = (k - 1) % l;
		if (count_bits(m) & 1) putchar(flip(s[d]));
		else putchar(s[d]);
	}
	return 0;
}

// SS'S'SS'SSS
// block 0 000 S
// block 1 001 S'
// block 2 010 S'
// block 3 011 S
// block 4 100 S'
// block 5 101 S
// block 6 110 S
// block 7 111 S'
