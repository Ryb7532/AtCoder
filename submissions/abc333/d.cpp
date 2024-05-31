#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

vector<vector<int>> E;
vector<int> C;

void dfs(int n, int p) {
  C[n] = 1;
  for (int u: E[n]) {
    if (u == p)
      continue;
    dfs(u, n);
    C[n] += C[u];
  }
}


int main() {
  int N;
  cin >> N;
  E.resize(N);
  C.resize(N);
  rep(i,N-1) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  dfs(0, -1);
  int maxc = 0;
  for (int u: E[0]) {
    chmax(maxc, C[u]);
  }
  print(N-maxc);
  return 0;
}