  set<pair<int, int>> b;
  auto add_bridge = [&] (int u, int v) {
    if (u > v) swap(u, v);
    b.insert(make_pair(u, v));
  };
  auto is_bridge = [&] (int u, int v) {
    if (u > v) swap(u, v);
    return b.find(make_pair(u, v)) != b.end();
  };
  vector<int> low(n), tin(n), vis(n);
  int t = 0;
  function<void(int, int)> dfs = [&] (int cur, int prv) {
    vis[cur] = 1;
    low[cur] = tin[cur] = t++;
    for (auto &nxt : g[cur]) {
      if (nxt == prv) continue;
      if (vis[nxt]) {
        low[cur] = min(low[cur], low[nxt]);
      }
      else {
        dfs(nxt, cur);
        low[cur] = min(low[cur], low[nxt]);
        if (low[nxt] > tin[cur]) {
          add_bridge(cur, nxt);
        }
      }
    }
  };
  dfs(0, -1);
