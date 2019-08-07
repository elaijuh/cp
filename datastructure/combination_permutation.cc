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

  void permutation(int a[], int l, int r) { _permute(a, l, r); }
};

int main() {
  int a[5] = {1, 2, 3, 4, 5};
  CP cp;
  cout << "combination:" << endl;
  cp.combination(a, 5, 3);
  cout << "permutation:" << endl;
  cp.permutation(a, 0, 2);
  return 0;
}
