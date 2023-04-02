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
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int T;
  cin >> T;
  const int maxD = 1e9;
  rep(_,T) {
    int N,M;
    cin >> N >> M;
    vector<int> C(N);
    rep(i,N) {
      cin >> C[i];
    }
    vector<vector<vector<int>>> Edge(N, vector<vector<int>>(2));
    rep(i,M) {
      int u,v;
      cin >> u >> v;
      u--; v--;
      Edge[u][C[v]].push_back(v);
      Edge[v][C[u]].push_back(u);
    }
    vector<vector<int>> D(N, vector<int>(N, maxD));
    queue<pair<int,int>> q;
    q.push({0,N-1});
    D[0][N-1] = 0;
    while (!q.empty()) {
      auto top = q.front();
      q.pop();
      int a = top.first, b = top.second;
      int d = D[a][b];
      for (int na: Edge[a][0]) {
        for (int nb: Edge[b][1]) {
          if (D[na][nb] == maxD) {
            q.push({na,nb});
          }
          D[na][nb] = min(D[na][nb], d+1);
        }
      }
      for (int na: Edge[a][1]) {
        for (int nb: Edge[b][0]) {
          if (D[na][nb] == maxD) {
            q.push({na,nb});
          }
          D[na][nb] = min(D[na][nb], d+1);
        }
      }
    }
    if (D[N-1][0] == maxD)
      D[N-1][0] = -1;
    print(D[N-1][0]);
  }
  return 0;
}
