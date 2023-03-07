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
  vector<set<int>> E(N);
  rep(_,M) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    E[u].insert(v);
    E[v].insert(u);
  }
  int res = 0;
  rep(a,N) {
    rep(b,N) {
      if (a == b)
        continue;
      rep(c,N) {
        if (a == c || b == c)
          continue;
        if (E[a].find(b) != E[a].end() && E[b].find(c) != E[b].end() && E[c].find(a) != E[c].end())
          res++;
      }
    }
  }
  print(res/6);
  return 0;
}
