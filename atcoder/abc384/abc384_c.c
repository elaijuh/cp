// https://atcoder.jp/contests/abc384/tasks/abc384_c
// #string #sort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int s[5];

char* r[31] = {"ABCDE", "BCDE", "ACDE", "ABDE", "ABCE", "ABCD", "CDE", "BDE",
			   "ADE",	"BCE",	"ACE",	"BCD",	"ABE",	"ACD",	"ABD", "ABC",
			   "DE",	"CE",	"BE",	"CD",	"AE",	"BD",	"AD",  "BC",
			   "AC",	"AB",	"E",	"D",	"C",	"B",	"A"};

int cmp(const void* a, const void* b) {
	int ka = 0, kb = 0;
	const char* sa = *(const char**)a;
	const char* sb = *(const char**)b;

	for (int i = 0; i < strlen(sa); i++) ka += s[sa[i] - 'A'];
	for (int i = 0; i < strlen(sb); i++) kb += s[sb[i] - 'A'];

	if (ka > kb) return -1;
	else if (ka == kb) return strcmp(sa, sb);
	else return 1;
}

int main() {
	for (int i = 0; i < 5; i++) scanf("%d", &s[i]);
	qsort(r, 31, sizeof(char*), cmp);
	for (int i = 0; i < 31; i++) printf("%s\n", r[i]);
	return 0;
}
