#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int N,M;
vector<pair<int, int>> pf;
ll res = 0;

void dfs(int id, ll v) {
  if (id==pf.size()) {
    if (v*N<=M)
      res = max(res, v);
    return;
  }
  ll pow = 1;
  rep(i, pf[id].second+1) {
    dfs(id+1, v*pow);
    pow*=pf[id].first;
  }
}

int main() {
  cin >> N >> M;
  int m = M;
  for (ll i=2; i*i<=m; i++) {
    if (m%i == 0) {
      int cnt = 0;
      while (m%i == 0) {
        m/=i;
        cnt++;
      }
      pf.push_back({i,cnt});
    }
  }
  if (m!=1) {
    pf.push_back({m,1});
  }
  dfs(0,1);
  print(res);
  return 0;
}
