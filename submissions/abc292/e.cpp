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
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> hasPath(N, vector<bool>(N, false));
  vector<set<int>> E(N);
  rep(_,M) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    E[u].insert(v);
  }
  rep(i,N) {
    queue<int> q;
    q.push(i);
    hasPath[i][i] = true;
    while(!q.empty()) {
      int top = q.front();
      q.pop();
      for (int next: E[top]) {
        if (hasPath[i][next])
          continue;
        hasPath[i][next] = true;
        q.push(next);
      }
    }
  }
  int res = 0;
  rep(i,N) {
    rep(j,N) {
      if (i == j)
        continue;
      if (E[i].find(j) != E[i].end())
        continue;
      if (!hasPath[i][j])
        continue;
      res++;
    }
  }
  print(res);
}
