typedef int Rank;
#define ListNodePosi(T) ListNode<T>*

template <typename T>
struct ListNode {
  T data;
  ListNodePosi(T) pred;
  ListNodePosi(T) succ;
  ListNode() {}
  ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
      : data(e), pred(p), succ(s) {}
  ListNodePosi(T) insertAsPred(T const& e) {
    ListNodePosi(T) x = new ListNode(e, pred, this);
    pred->succ = x;
    pred = x;
    return x;
  }
  ListNodePosi(T) insertAsSucc(T const& e) {
    ListNodePosi(T) x = new ListNode(e, this, succ);
    succ->pred = x;
    succ = x;
    return x;
  }
};

template <typename T>
class List {
 private:
  int _size;
  ListNodePosi(T) header;
  ListNodePosi(T) trailer;

 protected:
  void init() {
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer;
    header->pred = NULL;
    trailer->pred = header;
    trailer->succ = NULL;
    _size = 0;
  }
  int clear() {
    int oldSize = _size;
    while (_size) remove(header->succ);
    return oldSize;
  }
  void copyNodes(ListNodePosi(T), int);
  void merge(ListNodePosi(T) & p, int n, List<T>& L, ListNodePosi(T) q, int m) {
    ListNodePosi(T) pp = p->pred;
    while (0 < m)
      if ((0 < n) && (p->data <= q->data)) {
        if (q == (p = p->succ)) break;
        n--;
      } else {
        insertB(p, L.remove((q = q->succ)->pred));
        m--;
      }
    p = pp->succ;
  }
  void mergeSort(ListNodePosi(T) &, int);
  void selectionSort(ListNodePosi(T), int);
  void insertionSort(ListNodePosi(T), int);

 public:
  List() { init(); }
  List(List<T> const& L);
  List(List<T> const& L, Rank r, int n);
  List(ListNodePosi(T) p, int n);
  ~List() {
    clear();
    delete header;
    delete trailer;
  }
  Rank size() const { return _size; }
  bool empty() const { return _size <= 0; }
  T& operator[](Rank r) const {
    ListNodePosi(T) p = first();
    while (r--) p = p->succ;
    return p->data;
  }
  ListNodePosi(T) first() const { return header->succ; }
  ListNodePosi(T) last() const { return trailer->pred; }
  bool valid(ListNodePosi(T) p) { return p && (trailer != p) && (header != p); }
  ListNodePosi(T) find(T const& e) const { return find(e, _size, trailer); }
  ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const {
    while (n--)
      if (e == (p = p->pred)->data) return p;
    return NULL;
  }
  ListNodePosi(T) search(T const& e) const { return search(e, _size, trailer); }
  ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const;
  ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);
  ListNodePosi(T) selectMax() { return selectMax(header->succ, _size); }
  ListNodePosi(T) insertAsFirst(T const& e) {
    _size++;
    return header->insertAsSucc(e);
  }
  ListNodePosi(T) insertAsLast(T const& e) {
    _size++;
    return trailer->insertAsPred(e);
  }
  ListNodePosi(T) insertA(ListNodePosi(T) p, T const& e) {
    _size++;
    return p->insertAsSucc(e);
  }
  ListNodePosi(T) insertB(ListNodePosi(T) p, T const& e) {
    _size++;
    return p->insertAsPred(e);
  }
  T remove(ListNodePosi(T) p) {
    T e = p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete p;
    _size--;
    return e;
  }
  void merge(List<T>& L) { merge(first(), _size, L, L.first(), L.size()); }
  void sort(ListNodePosi(T) p, int n);
  void sort() { sort(first(), _size); }
  int deduplicate();
  int uniquify();
  void reverse();
  void traverse(void (*visit)(T&)) {
    for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ)
      visit(p->data);
  }
  template <typename VST>
  void traverse(VST&);
};
