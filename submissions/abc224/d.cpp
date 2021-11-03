#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int M;
  cin >> M;
  vec<vec<int>> Edge(9);
  rep(_,M) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    Edge[u].push_back(v);
    Edge[v].push_back(u);
  }
  ll res = -1;
  vec<int> init_stat(9,-1);
  vec<int> final_stat(9,-1);
  rep(i,8) {
    int p;
    cin >> p;
    p--;
    init_stat[p] = i;
    final_stat[i] = i;
  }
  set<vec<int>> used;
  used.insert(init_stat);
  queue<pair<vec<int>,ll>> q;
  q.push({init_stat,0});
  while(!q.empty()) {
    auto top = q.front();
    auto stat = top.first;
    ll cost = top.second;
    q.pop();
    if (stat == final_stat) {
      res = cost;
      break;
    }
    int emp;
    rep(i,9) {
      if (stat[i]==-1)
        emp = i;
    }
    for (int e: Edge[emp]) {
      vec<int> next_stat = stat;
      swap(next_stat[e], next_stat[emp]);
      if (used.find(next_stat) == used.end()) {
        used.insert(next_stat);
        q.push({next_stat, cost+1});
      }
    }
  }
  print(res);
  return 0;
}
