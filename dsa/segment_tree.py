class SegmentTree:
    def __init__(self, arr, op=sum):
        self.n = len(arr)
        self.t = [0] * (4 * self.n)
        self.op = op
        self._build(arr, 1, 0, self.n - 1)

    def _build(self, arr, v, tl, tr):
        if tl == tr:
            self.t[v] = arr[tl]
            return
        tm = (tl + tr) // 2
        self._build(arr, 2 * v, tl, tm)
        self._build(arr, 2 * v + 1, tm + 1, tr)
        self.t[v] = self.op([self.t[2 * v], self.t[2 * v + 1]])

    def update(self, i, val):
        self._update(1, 0, self.n - 1, i, val)

    def _update(self, v, tl, tr, i, val):
        if tl == tr:
            self.t[v] = val
            return
        tm = (tl + tr) // 2
        if tl <= i <= tm:
            self._update(2 * v, tl, tm, i, val)
        else:
            self._update(2 * v + 1, tm + 1, tr, i, val)
        self.t[v] = self.op([self.t[2 * v], self.t[2 * v + 1]])

    def query(self, l, r):
        return self._query(1, 0, self.n - 1, l, r)

    def _query(self, v, tl, tr, l, r):
        if l > r or tl > r or tr < l:
            return 0
        if tl == l and tr == r:
            return self.t[v]
        tm = (tl + tr) // 2
        return self.op(
            [
                self._query(2 * v, tl, tm, l, min(r, tm)),
                self._query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r),
            ]
        )


if __name__ == "__main__":
    t = SegmentTree([1, 2, 3, 4, 5], sum)
    print(t.query(2, 4))
