//http://www.spoj.com/problems/TEST/
#include <stdio.h>

int main() {
	int n;
	while (scanf("%d", &n)) {
		if (n != 42)
			printf("%d\n", n);
		else
			break;
	}

	return 0;
}