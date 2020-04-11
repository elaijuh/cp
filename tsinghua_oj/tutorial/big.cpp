#include <cstdio>

using namespace std;

int main() {
  setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
  setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
  int n, a, b;
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d", &a, &b);
    printf("%d\n", a + b);
  }
  return 0;
}
