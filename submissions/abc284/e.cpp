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
#define printYorN(f) cout << (f ? Yes : No) << endl


int N,M;
vector<vector<int>> Edge(2e5);
vector<bool> used(2e5, false);
int res = 0;

void dfs(int n) {
  used[n] = true;
  res++;
  if (res == 1e6)
    return;
  for (int e: Edge[n]) {
    if (used[e])
      continue;
    dfs(e);
    if (res == 1e6)
      return;
  }
  used[n] = false;
}

int main() {
  cin >> N >> M;
  rep(i,M) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    Edge[u].push_back(v);
    Edge[v].push_back(u);
  }
  dfs(0);
  print(res);
  return 0;
}
