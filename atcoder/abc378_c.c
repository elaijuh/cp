// https://atcoder.jp/contests/abc378/tasks/abc378_c
#include <stdio.h>

int h[1000000001];

int main() {
	int n, a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (h[a] > 0) printf("%hd ", h[a]);
		else printf("-1 ");
		h[a] = i + 1;
	}
	return 0;
}
