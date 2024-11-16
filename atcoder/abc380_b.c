// https://atcoder.jp/contests/abc380/tasks/abc380_b
#include <stdio.h>
#include <string.h>

int main() {
	char s[101];
	scanf("%s", s);
	int k = 0;
	for (int i = 1; i < strlen(s); i++) {
		if (s[i] == '-') k++;
		else {
			printf("%d ", k);
			k = 0;
		}
	}
	puts("");
	return 0;
}
