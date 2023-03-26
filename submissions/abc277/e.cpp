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
  int N,M,K;
  cin >> N >> M >> K;
  vector<vector<vector<int>>> E(N, vector<vector<int>>(2));
  rep(_,M) {
    int u,v,a;
    cin >> u >> v >> a;
    u--; v--;
    E[u][a].push_back(v);
    E[v][a].push_back(u);
  }
  vector<bool> S(N, false);
  rep(_,K) {
    int s;
    cin >> s;
    S[--s] = true;
  }
  using State = pair<int,int>;
  queue<pair<State,int>> q;
  set<State> seen;
  q.push({{0, 1}, 0});
  seen.insert({0, 1});
  if (S[0]) {
    q.push({{0, 0}, 0});
    seen.insert({0, 0});
  }
  int res = -1;
  while (!q.empty()) {
    auto top = q.front();
    q.pop();
    int n = top.first.first, s = top.first.second, d = top.second;
    if (n == N-1) {
      if (res == -1)
        res = d;
      else
        res = min(res, d);
      continue;
    }
    for (int e: E[n][s]) {
      if (seen.find({e, s}) == seen.end()) {
        q.push({{e, s}, d+1});
        seen.insert({e, s});
      }
      if (S[e] && seen.find({e, 1-s}) == seen.end()) {
        q.push({{e, 1-s}, d+1});
        seen.insert({e, 1-s});
      }
    }
  }
  print(res);
  return 0;
}
