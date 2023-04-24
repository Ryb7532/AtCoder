#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define rrep(i,n) for (int i=(int)(n)-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int N,M;
  cin >> N >> M;
  vector<vector<int>> Edge(N+1);
  rep(_,M) {
    int u,v;
    cin >> u >> v;
    if (u != 0)
      Edge[u].push_back(v);
    Edge[v].push_back(u);
  }
  const int INF = 1e9;
  vector<int> from_s(N+1,INF), to_e(N+1,INF);
  from_s[1] = 0;
  to_e[N] = 0;
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int n = q.front();
    q.pop();
    for (int d: Edge[n]) {
      if (from_s[d] != INF)
        continue;
      from_s[d] = from_s[n]+1;
      q.push(d);
    }
  }
  q.push(N);
  while (!q.empty()) {
    int n = q.front();
    q.pop();
    for (int d: Edge[n]) {
      if (to_e[d] != INF)
        continue;
      to_e[d] = to_e[n]+1;
      q.push(d);
    }
  }
  rep(i,N) {
    int res = min(from_s[N], min(from_s[0], from_s[i+1])+min(to_e[0], to_e[i+1]));
    if (res >= INF)
      res = -1;
    cout << res << " ";
  }
  cout << endl;
  return 0;
}
