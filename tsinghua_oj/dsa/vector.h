typedef int Rank;
#define DEFAULT_CAPICITY 3

template <typename T>
class Vector {
 protected:
  Rank _size;
  int _capicity;
  T* _elem;
  void copyFrom(T const* A, Rank lo, Rank hi) {
    _elem = new T[_capicity = 2 * (hi - lo)];
    _size = 0;
    while (lo < hi) _elem[_size++] = A[lo++];
  }
  void expand() {
    if (_size < _capicity) return;
    if (_capicity < DEFAULT_CAPICITY) _capicity = DEFAULT_CAPICITY;
    T* oldElem = _elem;
    _elem = new T[_capicity <<= 1];
    for (int i = 0; i < _size; i++) _elem[i] = oldElem[i];
    delete[] oldElem;
  }
  void merge(Rank lo, Rank mi, Rank hi) {
    T* A = _elem + lo;
    int lb = mi - lo;
    T* B = new T[lb];
    for (Rank i = 0; i < lb; i++) B[i] = A[i];
    int lc = hi - mi;
    T* C = _elem + mi;
    for (Rank i = 0, j = 0, k = 0; j < lb;) {
      A[i++] = (lc <= k || B[j] < C[k]) ? B[j++] : C[k++];
    }
    delete[] B;
  }
  void mergeSort(Rank lo, Rank hi) {
    if (hi - lo < 2) return;
    int mi = (hi + lo) >> 1;
    mergeSort(lo, mi);
    mergeSort(mi, hi);
    merge(lo, mi, hi);
  }

 public:
  Vector(int c = DEFAULT_CAPICITY, int s = 0, T v = 0) {
    _elem = new T[_capicity = c];
    for (_size = 0; _size < s; _elem[_size++] = v)
      ;
  }
  ~Vector() { delete[] _elem; }
  // read
  Rank size() { return _size; }
  bool empty() { return !_size; }
  Rank find(T const& e) const { return find(e, 0, _size); }
  Rank find(T const& e, Rank lo, Rank hi) const {
    while (lo < hi-- && e != _elem[hi])
      ;
    return hi;
  }
  //   Rank search(T const& e) const {
  //     return (0 >= _size) ? -1 : search(e, 0, _size);
  //   }
  //   Rank search(T const& e, Rank lo, Rank hi) cosnt;
  // write
  T& operator[](Rank r) { return _elem[r]; }
  const T& operator[](Rank r) const { return _elem[r]; }  // right value only
  Vector<T>& operator=(Vector<T> const& V) {
    if (_elem) delete[] _elem;
    copyFrom(V, 0, V.size());
    return *this;
  }
  Rank insert(Rank r, T const& e) {
    expand();
    for (int i = _size; i > r; i--) _elem[i] = _elem[i - 1];
    _elem[r] = e;
    _size++;
    return r;
  }
  Rank insert(T const& e) { return insert(_size, e); }
  void sort(Rank lo, Rank hi) { mergeSort(lo, hi); }
  void sort() { sort(0, _size); }
  //
  void traverse(void (*visit)(T&)) {
    for (int i = 0; i < _size; i++) visit(_elem[i]);
  }
};
