// https://atcoder.jp/contests/abc373/tasks/abc373_b
#include "stdio.h"

int main()
{
	char s[26];
	int a[26];
	scanf("%s", s);
	for (int i = 0; i < 26; i++)
		a[s[i] - 'A'] = i;
	int res = 0;
	for (int i = 0; i < 25; i++)
		if (a[i] > a[i + 1])
			res += a[i] - a[i + 1];
		else
			res += a[i + 1] - a[i];
	printf("%d\n", res);
	return 0;
}
