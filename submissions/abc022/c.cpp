#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end()

//warshall_floyd
const int MAX_V = 300;
const ll INF = 1e9;
int V;
ll d[MAX_V][MAX_V];

void init() {
  for (int i=0; i<V; i++)
    for (int j=0; j<V; j++)
      if (i != j)
        d[i][j] = INF;
}

void warshall_floyd() {
  for (int k=0; k<V; k++) {
    for (int i=0; i<V; i++) {
      for (int j=0; j<V; j++) {
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
      }
    }
  }
}
int main() {
  int M;
  cin >> V >> M;
  int u, v;
  ll l;
  vector<pair<int, ll>> from1;
  init();
  rep(i, M) {
    cin >> u >> v >> l;
    u--; v--;
    if (u == 0 || v == 0) {
      from1.push_back(make_pair(max(u, v), l));
    } else {
      d[u][v] = d[v][u] = l;
    }
  }
  warshall_floyd();
  int n = from1.size();
  ll ans = 1e9;
  rep(i, n) {
    reps(j, i+1, n) {
      ll tmp = from1[i].second+from1[j].second;
      tmp += d[from1[i].first][from1[j].first];
      ans = min(ans, tmp);
    }
  }
  if (ans == INF)
    ans = -1;
  print(ans);
  return 0;
}
