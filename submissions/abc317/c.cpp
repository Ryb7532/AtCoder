#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl

int N;
vector<vector<pair<int,int>>> E(10);
vector<bool> used(10, false);
int res = 0;

void dfs(int n, int c) {
  for (auto [nc, cost]: E[n]) {
    if (used[nc])
      continue;
    used[nc] = true;
    dfs(nc, c+cost);
    used[nc] = false;
  }
  res = max(res, c);
}

int main() {
  int M;
  cin >> N >> M;
  rep(_,M) {
    int A,B,C;
    cin >> A >> B >> C;
    A--; B--;
    E[A].push_back({B,C});
    E[B].push_back({A,C});
  }
  rep(i,N) {
    used[i] = true;
    dfs(i, 0);
    used[i] = false;
  }
  print(res);
  return 0;
}