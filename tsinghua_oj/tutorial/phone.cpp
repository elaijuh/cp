#include <cstdio>

int main() {
  int h1, m1, s1, h2, m2, s2;
  scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
  int d = h2 * 3600 + m2 * 60 + s2 - h1 * 3600 - m1 * 60 - s1;
  if (d < 0) d += 24 * 3600;
  printf("%d\n", d);
  return 0;
}
