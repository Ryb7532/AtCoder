#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep1(n) rep2(_,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define printyn(f) cout << ((f) ? "Yes" : "No") << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}
void print() {cout << endl;}
template<typename Arg, typename... Args> void print(const Arg a, const Args... b) {
  cout << a;
  (cout << ... << (cout << ' ', b)) << endl;
}

// Union Find Tree
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
  int &operator[](const int i) { return par[i]; }
};

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  UnionFind G(N);
  rep(i,N) {
    cin >> A[i];
    A[i]--;
    G.unite(i,A[i]);
  }
  ll res = 0;
  vector<int> dist(N, -1);
  vector<bool> incycle(N, false);
  map<int,ll> cycle;
  rep(i,N) {
    if (G.root(i) != i)
      continue;
    int n = i;
    ll d = 0;
    while (true) {
      if (dist[n] != -1) {
        cycle[i] = d-dist[n];
        break;
      }
      dist[n] = d++;
      n = A[n];
    }
    while (!incycle[n]) {
      incycle[n] = true;
      n = A[n];
    }
  }
  dist.assign(N, -1);
  rep(i,N) {
    if (dist[i] != -1) {
      res += dist[i];
      continue;
    }
    if (incycle[i]) {
      dist[i] = cycle[G.root(i)];
      res += dist[i];
      continue;
    }
    vector<int> st;
    st.push_back(i);
    while (true) {
      int n = st.back();
      if (dist[n] != -1)
        break;
      if (incycle[n]) {
        dist[n] = cycle[G.root(i)];
        break;
      }
      st.push_back(A[n]);
    }
    int d = dist[st.back()];
    st.pop_back();
    while (!st.empty()) {
      dist[st.back()] = ++d;
      st.pop_back();
    }
    res += dist[i];
  }
  print(res);
  return 0;
}