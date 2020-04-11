#include <cstdio>
#include <cstdlib>

int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int binSearch(int* s, const int& e, int lo, int hi) {
  while (lo < hi) {
    int mi = (hi + lo) >> 1;
    e < s[mi] ? hi = mi : lo = mi + 1;  // [lo, mi) or (mi, hi)
  }
  return --lo;
}

int main() {
  setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
  setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
  int n, m, a, b, c;
  scanf("%d%d", &n, &m);
  int v[n];
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  qsort(v, n, sizeof(int), compare);
  while (m--) {
    scanf("%d%d", &a, &b);
    int ai = binSearch(v, a, 0, n), bi = binSearch(v, b, 0, n);
    int res = bi - ai;
    if (v[ai] == a) res++;
    printf("%d\n", res);
  }
  return 0;
}
