struct SegmentTree {
vector<int> t;
int n;
  SegmentTree(int n_) {
    n = n_;
    t.assign(4 * n, 0);
  }
  void pointUpdate(int v, int l, int r, int pos, int val) {
    if (l == r) {
      t[v] = val;
    }
    else {
      int m = (l + r) / 2;
      if (pos <= m) {
        pointUpdate(v * 2, l, m, pos, val);
      }
      else {
        pointUpdate(v * 2 + 1, m + 1, r, pos, val);
      }
    }
  }
  void pointUpdate(int pos, int val) {
    pointUpdate(1, 0, n - 1, pos, val);
  }
  int query(int v, int l, int r, int ql, int qr) {
    if (qr < l || ql > r) {
      return 0LL;
    }
    if (ql <= l && r <= qr) {
      return t[v];
    }
    int m = (l + r) / 2;
    return query(v * 2, l, m, ql, qr) + query(v * 2 + 1, m + 1, r, ql, qr);
  }
  int query(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }
};
