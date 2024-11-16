// https://atcoder.jp/contests/abc380/tasks/abc380_a
#include <stdio.h>

int main() {
	char s[7];
	int a[10];
	scanf("%s", s);
	for (int i = 0; i < 6; i++) a[s[i] - 48]++;
	if (a[1] == 1 && a[2] == 2 && a[3] == 3) puts("Yes");
	else puts("No");
	return 0;
}
