using Node = array<int, 30>;

struct LazySegmentTree {
  vector<Node> t;
  vector<int> s;
  Node neutral = array<int, 30> {};
  int n;

  LazySegmentTree(vector<int> &a) {
    n = (int) a.size();
    t.assign(4 * n, Node{});
    s.assign(4 * n, 0);
    build(1, 0, n - 1, a);
  }
  
  Node merge(Node a, Node b) {
    auto c = a;
    for (int i = 0; i < 30; ++i) {
      c[i] += b[i];
    }
    return c;
  }

  void build(int v, int l, int r, vector<int> &a) {
    if (l == r) {
      for (int i = 0; i < 30; ++i) {
        t[v][i] += a[l] >> i & 1;
      }
    }
    else {
      int m = (l + r) / 2;
      build(v * 2, l, m, a);
      build(v * 2 + 1, m + 1, r, a);
      t[v] = merge(t[v * 2], t[v * 2 + 1]);
    }
  }

  void apply(int v, int l, int r) {
    if (s[v]) {
      for (int i = 0; i < 30; ++i) {
        if (s[v] >> i & 1) {
          t[v][i] = r - l + 1 - t[v][i]; 
        }
      }
      if (l != r) {
        s[v * 2] ^= s[v];
        s[v * 2 + 1] ^= s[v];
      }
      s[v] = 0;
    }
  }

  void rangeApply(int v, int l, int r, int ql, int qr, int x) {
    apply(v, l, r);
    if (ql > r || qr < l) {
      return;
    }
    if (ql <= l && r <= qr) {
      s[v] ^= x;
      apply(v, l, r);
      return;
    }
    int m = (l + r) / 2;
    rangeApply(v * 2, l, m, ql, qr, x);
    rangeApply(v * 2 + 1, m + 1, r, ql, qr, x);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
  }
  
  void rangeApply(int l, int r, int x) {
    rangeApply(1, 0, n - 1, l, r, x);
  }

  Node query(int v, int l, int r, int ql, int qr) {
    apply(v, l, r);
    if (ql > r || qr < l) {
      return Node{};
    }
    if (ql <= l && r <= qr) {
      return t[v];
    }
    int m = (l + r) / 2;
    return merge(query(v * 2, l, m, ql, qr), query(v * 2 + 1, m + 1, r, ql, qr));
  }

  int query(int l, int r) {
    auto b = query(1, 0, n - 1, l, r);
    int sum = 0;
    for (int i = 0; i < 30; ++i) {
      sum += (1 << i) * b[i];
    }
    return sum;
  }
};
