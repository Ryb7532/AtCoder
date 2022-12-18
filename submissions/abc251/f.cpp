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

const int maxN = 2e5;
vector<vector<int>> E(maxN);
vector<pair<int, int>> T1, T2;
vector<bool> used1(maxN, false), used2(maxN, false);

void dfs(int s) {
  used1[s] = true;
  for (int t : E[s]) {
    if (used1[t])
      continue;
    T1.push_back({s,t});
    dfs(t);
  }
}

void bfs() {
  queue<int> q;
  q.push(0);
  used2[0] = true;
  while (!q.empty()) {
    int s = q.front();
    q.pop();
    for (int t : E[s]) {
      if (used2[t])
        continue;
      T2.push_back({s,t});
      q.push(t);
      used2[t] = true;
    }
  }

}

int main() {
  int N,M;
  cin >> N >> M;
  rep(_,M) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  dfs(0);
  bfs();
  rep(i,N-1) {
    print(T1[i].first + 1 << " " << T1[i].second + 1);
  }
  rep(i,N-1) {
    print(T2[i].first + 1 << " " << T2[i].second + 1);
  }
  return 0;
}
