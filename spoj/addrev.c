// http://www.spoj.com/problems/ADDREV/

#include <stdio.h>
#include <string.h>

int rev(char *a, int l)
{
	int i, t;

	for (i = 0; i < l / 2; i++) {
		t = a[i];
		a[i] = a[l - 1 - i];
		a[l - 1 - i] = t;
	}
	return 0;
}

int add(char *a, char *b, char *c, int la, int lb)
{
	int i, j, k, s, f = 0;
	for (i = la - 1, j = lb - 1, k = 0; i >= 0 || j >= 0; i--, j--, k++) {
		if (i < 0) {
			s = b[j] - 48 + f;
		} else if (j < 0) {
			s = a[i] - 48 + f;
		} else {
			s = a[i] + b[j] - 96 + f;
		}
		f = (s >= 10) ? 1 : 0;
		c[k] = s % 10 + 48;
	}
	if (f) {
		c[k] = '1';
		c[k + 1] = '\0';
	} else {
		c[k] = '\0';
	}
	return 0;
}

char *nozero(char *s)
{
	int i, l = strlen(s);
	for (i = 0; i < l; i++)
		if (s[i] != '0')
			break;
	return s + i;
}

int main()
{
	int n, la, lb;
	char a[100], b[100], c[100];
	scanf("%d", &n);
	while (n--) {
		scanf("%s%s", a, b);
		la = strlen(a), lb = strlen(b);
		rev(a, la);
		rev(b, lb);
		add(a, b, c, la, lb);
		printf("%s\n", nozero(c));
	}
	return 0;
}
