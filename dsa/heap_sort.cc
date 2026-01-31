/*
    Implement a priority queue by min heap
 */
#include <iostream>
using namespace std;

#define PQ_SIZE 100

class PQ {
  struct priority_queue {
    int q[PQ_SIZE];
    int n;
    priority_queue(int n) : n(n) {}
  };

  priority_queue *pq;

  void bubble_up(int n) {
    if (n == 1) return;
    if (pq->q[n] < pq->q[n / 2]) {
      swap(pq->q[n], pq->q[n / 2]);
      bubble_up(n / 2);
    }
  }

  void bubble_down(int n) {
    int min = n;
    int c = 2 * n;
    for (int i = 0; i < 2; i++) {
      if (c + i <= pq->n) {
        if (pq->q[min] > pq->q[c + i]) {
          min = c + i;
        }
      }
    }
    if (min != n) {
      swap(pq->q[n], pq->q[min]);
      bubble_down(min);
    }
  }

 public:
  PQ() {
    if (pq == nullptr) {
      pq = new priority_queue(0);
    }
  }
  ~PQ() {}

  void empty() { pq->n = 0; }

  int size() { return pq->n; }

  int top() {
    if (pq->n <= 0) {
      cout << "Warning: priority queue is empty" << endl;
      return 0;
    }
    return pq->q[1];
  }

  int pop() {
    if (pq->n <= 0) {
      cout << "Warning: priority queue is empty" << endl;
      return 0;
    }
    int min = pq->q[1];
    pq->q[1] = pq->q[pq->n];
    pq->n = pq->n - 1;
    bubble_down(1);
    return min;
  }

  void push(int x) {
    if (pq->n == PQ_SIZE) {
      cout << "Warning: priority queue overflow" << endl;
    } else {
      pq->n = pq->n + 1;
      pq->q[pq->n] = x;
      bubble_up(pq->n);
    }
  }
};

int main() {
  PQ pq;
  int s[] = {5, 3, 11, 6, 4, 7};
  for (int i = 0; i < 6; i++) {
    pq.push(s[i]);
  }
  cout << "top: " << pq.top() << endl;

  // merge sort
  for (int i = 0; i < 6; i++) {
    s[i] = pq.pop();
    cout << s[i] << " ";
  }

  return 0;
}
