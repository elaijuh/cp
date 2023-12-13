// 2023-12-14
// Pythagoras is reported to have said that a friend is
// "one who is the other I, such as are 220 and 284"

#include <stdio.h>
#include <math.h>

#define N 10000

int d(int a)
{
	int sum = 0;
	for (int i = 1; i < sqrt(a); i++)
		if (a % i == 0)
			sum += i + a / i;
	return sum - a;
}

int main(int argc, char *argv[])
{
	int a[N];
	int sum = 0;
	for (int i = 3; i < N; i++)
		a[i] = d(i);
	for (int i = 3; i < N; i++)
		if (a[i] > 0 && a[i] < N && i != a[i] && i == a[a[i]]) {
			printf("%d %d\n", i, a[i]);
			sum += i + a[i];
			a[a[i]] = 0;
		}
	printf("%d\n", sum);
	return 0;
}
