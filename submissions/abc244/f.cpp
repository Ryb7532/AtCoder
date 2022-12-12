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


int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> E(N);
  rep(_,M) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> check((1<<N), false);
  vector<vector<bool>> visited((1<<N), vector<bool>(N, false));
  queue<pair<int,pair<int,int>>> q;
  long res = 0;
  check[0] = true;
  rep(i,N) {
    q.push({1, {1<<i, i}});
    visited[1<<i][i] = true;
  }
  while (!q.empty()) {
    auto top = q.front();
    q.pop();
    if (!check[top.second.first]) {
      res += top.first;
      check[top.second.first] = true;
    }
    for (int dist : E[top.second.second]) {
      int s = (top.second.first)^(1<<dist);
      if (visited[s][dist])
        continue;
      q.push({top.first+1, {s, dist}});
      visited[s][dist] = true;
    }
  }
  print(res);
  return 0;
}
