#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int h) {
  int aux[h - l + 1];
  int k = 0, i = l, j = m + 1;
  while (i <= m && j <= h) {
    if (a[i] < a[j]) {
      aux[k++] = a[i++];
    } else {
      aux[k++] = a[j++];
    }
  }

  while (i <= m) aux[k++] = a[i++];
  while (j <= h) aux[k++] = a[j++];

  cout << "aux: ";
  for (int i = 0; i <= h - l; i++) cout << aux[i] << " ";
  cout << endl;

  for (int i = l; i <= h; i++) a[i] = aux[i - l];

  cout << "a: ";
  for (int i = 0; i < 7; i++) cout << a[i] << " ";
  cout << endl;
}

void merge_sort(int a[], int l, int h) {
  int m;
  if (l < h) {
    m = (l + h) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, h);
    merge(a, l, m, h);
  }
}

int main() {
  int a[] = {2, 4, 3, 10, 6, 11, 4};

  merge_sort(a, 0, sizeof(a) / sizeof(int) - 1);
  return 0;
}
