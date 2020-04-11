#include <cstdio>

#define MAX 4000000

long long ans = 0;
struct point {
  int x, y;
} p[MAX];
int yv[MAX];

void mergeP(int lo, int mi, int hi) {
  point *A = p + lo;
  int lb = mi - lo;
  point *B = new point[lb];
  for (int i = 0; i < lb; i++) B[i] = A[i];
  int lc = hi - mi;
  point *C = p + mi;
  for (int i = 0, j = 0, k = 0; j < lb;) {
    A[i++] = (lc <= k || B[j].x < C[k].x) ? B[j++] : C[k++];
  }
  delete[] B;
}

void mergeV(int lo, int mi, int hi) {
  int *A = yv + lo;
  int lb = mi - lo;
  int *B = new int[lb];
  for (int i = 0; i < lb; i++) B[i] = A[i];
  int lc = hi - mi;
  int *C = yv + mi;
  for (int i = 0, j = 0, k = 0; j < lb;) {
    // A[i++] = (lc <= k || B[j] < C[k]) ? B[j++] : C[k++];
    if (lc <= k || B[j] <= C[k]) {
      ans += lc - k;
      A[i++] = B[j++];
    } else {
      A[i++] = C[k++];
    }
  }
  delete[] B;
}

void mergeSortP(int lo, int hi) {
  if (hi - lo < 2) return;
  int mi = (hi + lo) >> 1;
  mergeSortP(lo, mi);
  mergeSortP(mi, hi);
  mergeP(lo, mi, hi);
}

void mergeSortV(int lo, int hi) {
  if (hi - lo < 2) return;
  int mi = (hi + lo) >> 1;
  mergeSortV(lo, mi);
  mergeSortV(mi, hi);
  mergeV(lo, mi, hi);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &p[i].x, &p[i].y);
  }
  mergeSortP(0, n);
  for (int i = 0; i < n; i++) {
    yv[i] = p[i].y;
  }
  mergeSortV(0, n);
  printf("%lld\n", ans);

  return 0;
}
