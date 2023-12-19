// 2023-12-19
// Perfect binary tree
// Geometric series

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// #define N 31
// #define T 4
#define N 65535
#define T 15

char *tree;
int LCM = 360360;
unsigned long num = 0;

void traverse(int k, int n, unsigned long d)
{
	if (2 * k + 1 >= N) {
		if (n > 0)
			num += d;
		return;
	}
	traverse(2 * k + 1, n + 1, d); // blue
	traverse(2 * k + 2, n - 1, d * tree[2 * k + 2]); // red
}

int main(int argc, char *argv[])
{
	// char *tree;
	tree = (char *)calloc(N, sizeof(char));
	int i = 0, j, k;
	tree[i++] = 1;
	for (j = 1; j <= T; j++) {
		k = (int)pow(2, j);
		while (k--)
			tree[i++] = j;
	}
	traverse(0, 0, 1);
	unsigned long den;
	for (den = 1, i = 2; i <= T + 1; i++)
		den *= i;
	printf("P=%ld/%ld %ld\n", num, den, den / num);

	free(tree);
	return 0;
}
