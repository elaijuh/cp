// 2023-12-12
// Long multiplication

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char a[201], b[201], i, j, t, d;
	memset(a, 0, 201 * sizeof(char));
	memset(b, 0, 201 * sizeof(char));
	a[200] = 1;
	int k;
	int l = 1;
	int n = 2;
	int sum = 0;
	while (n < 100) {
		i = n % 10;
		j = n / 10;
		d = 0;
		for (k = 0; k < l; k++) {
			t = i * a[200 - k] + d;
			d = t / 10;
			t = t % 10;
			b[200 - k] = t;
		}
		if (d > 0) {
			b[200 - l] = d;
		}
		d = 0;
		for (k = 0; k < l; k++) {
			t = j * a[200 - k] + d + b[200 - k - 1];
			d = t / 10;
			t = t % 10;
			b[200 - k - 1] = t;
		}
		if (d > 0) {
			b[200 - l - 1] = d;
			l++;
		}
		l++;
		for (k = 0; k < l; k++)
			a[200 - k] = b[200 - k];
		n++;
	}

	printf("l=%d\nans=", l);
	for (k = l - 1; k >= 0; k--)
		printf("%c", b[200 - k] + 48);
	printf("\n");

	while (l--)
		sum += b[200 - l];
	printf("sum=%d\n", sum);

	return 0;
}
