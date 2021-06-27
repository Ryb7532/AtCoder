#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using iii = tuple<int, int, int>;

struct UnionFind {
  vector<int> par;

  UnionFind(int n) : par(n) {
    par.assign(n, -1);
  }

  int root(int a) {
    if (par[a] < 0)
      return a;
    return par[a] = root(par[a]);
  }

  int size(int a) {
    return -par[root(a)];
  }

  void unite(int a, int b) {
    int ra = root(a), rb = root(b);
    if (ra == rb)
      return;
    if (par[a]>par[b])
      swap(a, b);
    par[ra] += par[rb];
    par[rb] = ra;
    return;
  }

  bool same(int a, int b) {
    int ra = root(a), rb = root(b);
    return ra == rb;
  }
};

int main() {
  int N, M, a, b, y, Q, v, w;
  cin >> N >> M;
  vector<iii> r(M);
  for (int i=0; i<M; i++) {
    cin >> a >> b >> y;
    a--; b--;
    r.at(i) = make_tuple(y, a, b);
  }
  sort(r.begin(), r.end());
  cin >> Q;
  vector<iii> q(Q);
  for (int i=0; i<Q; i++) {
    cin >> v >> w;
    v--;
    q.at(i) = make_tuple(w, v, i);
  }
  sort(q.begin(), q.end());
  UnionFind tree(N);
  iii bq, br;
  vector<int> ans(Q, 0);
  while (!r.empty() || !q.empty()) {
    bq = q.back();
    br = r.back();
    if (get<0>(bq) >= get<0>(br)) {
      ans.at(get<2>(bq)) = tree.size(get<1>(bq));
      q.pop_back();
    } else {
      tree.unite(get<1>(br), get<2>(br));
      r.pop_back();
    }
  }
  while (!q.empty()) {
    bq = q.back();
    ans.at(get<2>(bq)) = tree.size(get<1>(bq));
    q.pop_back();
  }
  for (int i=0; i<Q; i++)
    cout << ans.at(i) << endl;
  return 0;
}
