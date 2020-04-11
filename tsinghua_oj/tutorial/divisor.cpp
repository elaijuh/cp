// 辗转相除
#include <cstdio>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  int r = 1;
  while (r) {
    r = a % b;
    a = b;
    b = r;
  }
  printf("%d\n", a);
  return 0;
}
