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
  const int INF = 1e9;
  int N,M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> Edge(N);
  rep(_,M) {
    int a,b;
    char c;
    cin >> a >> b >> c;
    a--; b--;
    Edge[a].push_back({b,c-'a'});
    if (a != b)
      Edge[b].push_back({a,c-'a'});
  }
  vector<vector<int>> dist(N, vector<int>(N, INF));
  queue<pair<int,int>> q;
  q.push({0,N-1});
  dist[0][N-1] = 0;
  dist[N-1][0] = 0;
  int res = INF;
  while (!q.empty()) {
    auto top = q.front();
    q.pop();
    int a = top.first;
    int b = top.second;
    vector<vector<int>> fromA(26);
    for (auto e: Edge[a]) {
      fromA[e.second].push_back(e.first);
    }
    for (auto e: Edge[b]) {
      for (int d: fromA[e.second]) {
        if (e.first == d)
          res = min(res, 2*dist[e.first][d]);
        if (e.first == a && d == b)
          res = min(res, 2*dist[a][b]+1);
        if (dist[e.first][d] != INF)
          continue;
        q.push({e.first, d});
        dist[e.first][d] = dist[a][b]+1;
        dist[d][e.first] = dist[a][b]+1;
      }
    }
  }
  if (res == INF)
    res = -1;
  print(res);
  return 0;
}
