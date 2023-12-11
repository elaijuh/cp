#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	long n = 600851475143;
	long f = 2;
	long ff = 1;
	while (n % f == 0) {
		n /= f;
		ff = f;
	}
	f = 3;
	while (n > 1 && f < sqrt(n)) {
		while (n % f == 0) {
			n /= f;
			ff = f;
		}
		f += 2;
	}
	if (n == 1)
		printf("%ld\n", ff);
	else
		printf("%ld\n", n);

	return 0;
}
