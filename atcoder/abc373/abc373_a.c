#include "stdio.h"
#include "string.h"

int main()
{
	char s[101];
	int t = 0;
	for (int i = 1; i <= 12; i++) {
		scanf("%s", s);
		if ((int)strlen(s) == i)
			t++;
	}
	printf("%d\n", t);
	return 0;
}
