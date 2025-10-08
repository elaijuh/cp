// https://atcoder.jp/contests/abc383/tasks/abc383_b

#include <stdio.h>

int h, w, d;
char c[10][10];

int man(int x, int y, char f, char t) {
	int k = 0;
	for (int i = 0; i <= d; i++) {
		for (int j = 0; j <= d - i; j++) {
			if (x + i < h && y + j < w && c[x + i][y + j] == f) {
				c[x + i][y + j] = t;
				k++;
			}
			if (x + i < h && y - j >= 0 && c[x + i][y - j] == f) {
				c[x + i][y - j] = t;
				k++;
			}
			if (x - i >= 0 && y + j < w && c[x - i][y + j] == f) {
				c[x - i][y + j] = t;
				k++;
			}
			if (x - i >= 0 && y - j >= 0 && c[x - i][y - j] == f) {
				c[x - i][y - j] = t;
				k++;
			}
		}
	}
	return k;
}

int main() {
	int h1, h2, ans = 0;
	scanf("%d %d %d", &h, &w, &d);
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) scanf(" %c", &c[i][j]);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (c[i][j] == '#') continue;
			h1 = man(i, j, '.', '[');
			for (int ii = i; ii < h; ii++) {
				int jj = 0;
				if (ii == i) jj = j + 1;
				for (; jj < w; jj++) {
					if (c[ii][jj] == '#') continue;
					h2 = man(ii, jj, '.', ']');
					if (h1 + h2 > ans) ans = h1 + h2;
					man(ii, jj, ']', '.');
				}
			}
			man(i, j, '[', '.');
		}
	}
	printf("%d\n", ans);
	return 0;
}
