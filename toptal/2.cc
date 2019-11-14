/*
题目要求给一个n长的数列A，对数列里的元素只能做减法，求操作过的元素最小以保证最后数列满足(A[i]-A[i-1])*(A[i+1]-A[i])<0
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int scan(vector<int> a, int p) {
  int n = a.size();
  vector<int> f(n, 0);
  for (int i = 1; i < n; i++) {
    if (p < 0) {
      if (a[i] - a[i - 1] <= 0) {
        a[i - 1] = a[i] - 1;
        f[i - 1] = 1;
      }
      p = 1;
    } else {
      if (a[i] - a[i - 1] >= 0) {
        a[i] = a[i - 1] - 1;
        f[i] = 1;
      }
      p = -1;
    }
  }

  int m = 0;
  for (int x : f) {
    m += x;
  }

  return m;
}

int solution(vector<int> &a) {
  int n = a.size();
  if (n <= 1) return 0;
  int ans = min(scan(a, -1), INT_MAX);
  ans = min(scan(a, 1), ans);

  return ans;
}

int main() {
  vector<int> A{5, 4, 3, 2, 6};
  int ans = solution(A);
  cout << ans << endl;
  return ans;
}
