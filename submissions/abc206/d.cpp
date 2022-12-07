#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"

struct UnionFind {
  vector<int> par;
  UnionFind(int n) : par(n, -1) {}

  int root(int a) {
    if (par[a] < 0)
      return a;
    return par[a] = root(par[a]);
  }
  int size(int a) { return -par[root(a)]; }
  void unite(int a, int b) {
    int ra = root(a), rb = root(b);
    if (ra == rb)
      return;
    if (par[ra]>par[rb])
      swap(ra, rb);
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
  int N;
  cin >> N;
  vec<int> A(N);
  map<int, vec<int>> idx;
  UnionFind uft(N);
  rep(i,N) {
    cin >> A[i];
    idx[A[i]].push_back(i);
  }
  for (auto &m: idx) {
    int a = m.second[0];
    for (auto &e: m.second) {
      uft.unite(a,e);
    }
  }
  int res = 0;
  rep(i,N/2) {
    if (uft.same(i,N-i-1))
      continue;
    res++;
    uft.unite(i,N-i-1);
  }
  print(res);
  return 0;
}
