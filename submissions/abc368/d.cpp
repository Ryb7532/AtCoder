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
template<class... T> void scan(T&... a) {(cin >> ... >> a);}

int N;
vector<vector<int>> E;
vector<int> C;

int dfs(int n, int p) {
  fore(d,E[n]) {
    if (d == p)
      continue;
    C[n] += dfs(d, n);
  }
  return C[n];
}

int main() {
  int K;
  scan(N,K);
  E.resize(N);
  C.assign(N,0);
  rep(_,N-1) {
    int a,b;
    scan(a,b);
    a--; b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  rep(_,K) {
    int v;
    scan(v);
    v--;
    C[v]++;
  }
  dfs(0, -1);
  int res = 0;
  queue<pair<int,int>> Q;
  Q.push({0, -1});
  vector<bool> F(N,true);
  while (Q.size() > 0 && Q.size() < 2) {
    auto [n, p] = Q.front();
    Q.pop();
    fore(d,E[n]) {
      if (d == p)
        continue;
      if (C[d] == 0)
        continue;
      Q.push({d, n});
      if (C[d] == K) {
        F[n] = false;
      }
    }
  }
  rep(i,N) {
    if (F[i] && C[i] > 0)
      res++;
  }
  print(res);
  return 0;
}