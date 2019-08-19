#include <iostream>
using namespace std;

class CP {
  // a: array
  // l: starting index
  // r: ending index
  void _permute(int a[], int l, int r) {
    if (l == r) {
      for (int k = 0; k <= r; k++) {
        cout << a[k] << " ";
      }
      cout << endl;
      return;
    }
    for (int i = l; i <= r; i++) {
      swap(a[l], a[i]);
      _permute(a, l + 1, r);
      swap(a[l], a[i]);
    }
  }

  // non recursive
  void _permute(int a[], int n) {
    if (n == 1) return;
    sort(a, a + n);
    while (true) {
      // print
      for (int k = 0; k < n; k++) {
        cout << a[k] << " ";
      }
      cout << endl;
      int i = n - 2;
      while (i >= 0 && a[i + 1] <= a[i]) i--;
      if (i < 0) break;
      int j = n - 1;
      while (j >= i && a[j] <= a[i]) j--;
      swap(a[i], a[j]);
      reverse(a + i + 1, a + n);
    }
  }

  // take r elements out of array whose lower index is i and higher index is n
  void _comb(int a[], int t[], int i, int n, int j, int r) {
    if (j == r) {
      for (int k = 0; k < r; k++) {
        cout << t[k] << " ";
      }
      cout << endl;
      return;
    }

    for (int k = i; k < n && n - k >= r - j; k++) {
      t[j] = a[k];
      _comb(a, t, k + 1, n, j + 1, r);
    }
  }

 public:
  // pick r items from n items
  // a: array
  void combination(int a[], int n, int r) {
    int t[r];
    _comb(a, t, 0, n, 0, r);
  }

  void permutation_recursive(int a[], int l, int r) { _permute(a, l, r); }

  void permutation_nonrecursive(int a[], int n) { _permute(a, n); }
};

int main() {
  int a[5] = {1, 2, 3, 4, 5};
  CP cp;
  cout << "combination:" << endl;
  cp.combination(a, 5, 3);
  cout << "permutation_recursive:" << endl;
  cp.permutation_recursive(a, 0, 4);
  cout << "permutation_nonrecursive:" << endl;
  cp.permutation_nonrecursive(a, 5);
  return 0;
}
