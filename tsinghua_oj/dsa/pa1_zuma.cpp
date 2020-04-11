#include <cstdio>

struct node {
  char data;
  node* pred;
  node* succ;
  node() {}
  node(char e, node* p = NULL, node* s = NULL) : data(e), pred(p), succ(s) {}
  node* insertAsPred(char e) {
    node* p = new node(e, pred, this);
    pred->succ = p;
    this->pred = p;
    return p;
  }
};

class list {
 private:
  int _size;
  node* header;
  node* trailer;

 protected:
  void init() {
    header = new node;
    trailer = new node;
    header->succ = trailer;
    header->pred = NULL;
    trailer->pred = header;
    trailer->succ = NULL;
    _size = 0;
  }

 public:
  list() { init(); }
  int size() { return _size; }
  node* first() { return header->succ; }
  node* last() { return trailer->pred; }
  node* insertB(node* p, char e) {
    _size++;
    return p->insertAsPred(e);
  }
  node* insertAsLast(char e) {
    _size++;
    return trailer->insertAsPred(e);
  }
  char remove(node* p) {
    char e = p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete p;
    _size--;
    return e;
  }
  void traverse() {
    for (node* p = header->succ; p != trailer; p = p->succ) {
      putchar(p->data);
    }
  }
};

int main() {
  char c;
  int n, k;
  list l;
  node* p;
  node* xl;
  node* xr;
  while ((c = getchar()) >= 'A' && c <= 'Z') {
    l.insertAsLast(c);
  }
  scanf("%d", &n);
  while (n--) {
    scanf("%d %c", &k, &c);
    p = l.first();
    while (k--) p = p->succ;
    p = l.insertB(p, c);
    while (true) {
      if (l.size() == 0) break;
      xl = xr = p;
      int cnt = 1;
      while (xl->pred && xl->pred->data == p->data) {
        xl = xl->pred;
        cnt++;
      }
      while (xr->succ && xr->succ->data == p->data) {
        xr = xr->succ;
        cnt++;
      }
      if (cnt >= 3) {
        p = xl->pred;
        while (cnt--) {
          xl = xl->succ;
          l.remove(xl->pred);
        }
        continue;
      }
      break;
    }
    if (l.size() == 0)
      putchar('-');
    else
      l.traverse();
    putchar('\n');
  }
  return 0;
}
