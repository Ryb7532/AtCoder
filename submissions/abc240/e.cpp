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


vector<vector<int>> Edge(2e5);
vector<pair<int,int>> res(2e5);
int id = 0;

void dfs(int n, int p) {
  bool leaf = true;
  for (int e: Edge[n]) {
    if (e==p)
      continue;
    leaf = false;
    dfs(e,n);
  }
  if (leaf) {
    id++;
    res[n] = {id,id};
  } else {
    int l=id,r=0;
    for (int e: Edge[n]) {
      if (e==p)
        continue;
      l = min(l, res[e].first);
      r = max(r, res[e].second);
    }
    res[n] = {l,r};
  }
}

int main() {
  int N;
  cin >> N;
  rep(i,N-1) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    Edge[u].push_back(v);
    Edge[v].push_back(u);
  }
  dfs(0,-1);
  rep(i,N) {
    print(res[i].first << ' ' << res[i].second);
  }
  return 0;
}
