#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N,M;
  cin >> N >> M;
  vector<ll> A(N);
  vector<ll> C(N, 0);
  vector<vector<int>> E(N);
  rep(i,N) {
    cin >> A[i];
  }
  rep(i,M) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
    C[u] += A[v];
    C[v] += A[u];
  }
  set<pair<ll,int>> cost;
  rep(i,N) {
    cost.insert({C[i], i});
  }
  ll res = 0;
  while (!cost.empty()) {
    auto top = cost.begin();
    ll c = top->first;
    int i = top->second;
    cost.erase(top);
    res = max(res, c);
    C[i] = 0;
    for (auto n: E[i]) {
      c = C[n];
      if (c == 0)
        continue;
      C[n] -= A[i];
      cost.erase(cost.find({c, n}));
      cost.insert({C[n], n});
    }
  }
  print(res);
  return 0;
}
