#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


//warshall_floyd
const int MAX_V = 300;
const int INF = 1e9;
int V;
ll d[MAX_V][MAX_V];

void init() {
  rep(i, V)
    rep(j, V)
      if (i != j)
        d[i][j] = INF;
}

void warshall_floyd() {
  rep(k, V)
    rep(i, V)
      rep(j, V)
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
}

int main() {
  int M, a, b, t;
  cin >> V >> M;
  init();
  rep(i, M) {
    cin >> a >> b >> t;
    a--; b--;
    d[a][b] = d[b][a] = t;
  }
  warshall_floyd();
  ll maxtime = INF;
  rep(i, V) {
    ll mt = 0;
    rep(j, V) {
      mt = max(mt, d[i][j]);
    }
    if (mt<maxtime) {
      maxtime = mt;
    }
  }
  print(maxtime);
  return 0;
}
