#include <cstdio>

int main() {
  double a, b, res;
  char c;
  std::scanf("%lf %c %lf", &a, &c, &b);
  switch (c) {
    case '+':
      res = a + b;
      break;
    case '-':
      res = a - b;
      break;
    case '*':
      res = a * b;
      break;
    default:
      res = a * b;
      break;
  }
  std::printf("%.0f", res);
  return 0;
}
