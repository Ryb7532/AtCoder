#include <bits/stdc++.h>
using namespace std;
using edge = struct {
  int next;
  long d;
};
vector<edge> tree[100000];
long depth[100000] = {};

void dfs(int n, int p, long d) {
  depth[n] = d;
  for (auto &e : tree[n]) {
    if (e.next == p)
      continue;
    dfs(e.next, n, d+e.d);
  }
}

int main() {
  int n;
  cin >> n;
  int a, b;
  long c;
  for (int i=0; i<n-1; i++) {
    cin >> a >> b >> c;
    a--;
    b--;
    tree[a].push_back({b, c});
    tree[b].push_back({a, c});
  }
  int q, k, x, y;
  cin >> q >> k;
  k--;
  dfs(k, -1, 0);
  for (int i=0; i<q; i++) {
    cin >> x >> y;
    cout << depth[x-1]+depth[y-1] << '\n';
  }
  return 0;
}
