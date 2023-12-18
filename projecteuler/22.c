#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int cmp(const void *a, const void *b)
{
	return strcmp(*(const char **)a, *(const char **)b);
}

int score(const char *s)
{
	int r = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '"')
			continue;
		r += s[i] - 'A' + 1;
	}
	return r;
}

int main(int argc, char *argv[])
{
	FILE *fp = fopen("projecteuler/22.txt", "r");
	if (fp == NULL) {
		printf("fail to open file\n");
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	char *buf;
	buf = (char *)malloc(size);
	fseek(fp, 0, SEEK_SET);
	fgets(buf, size, fp);
	char *name;
	char *names[6000];
	name = strtok(buf, ",");
	int i = 0;
	while (name != NULL) {
		names[i] = (char *)malloc(strlen(name) + 1);
		strcpy(names[i++], name);
		name = strtok(NULL, ",");
	}
	qsort(names, i, sizeof(names[0]), cmp);
	unsigned long t;
	for (t = 0; --i >= 0;) {
		t += (i + 1) * score(names[i]);
	}
	printf("%ld\n", t);

	free(buf);
	fclose(fp);

	return 0;
}
