#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())

//Dijkstra (no minus cost path)
const int MAX_V = 50;
const ll INF = 1LL << 50;
typedef struct{
  int to;
  ll cost;
  ll time;
} Edge;
typedef pair<ll,pair<int,ll>> P; //first:dis second:num

ll d[MAX_V][2501];
vector<Edge> G[MAX_V];

void dijkstra(int m) {
  rep(i,MAX_V) {
    rep(j,2501) {
      d[i][j] = INF;
    }
  }
  m = min(m, 2500);
  d[0][m] = 0;

  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, make_pair(0,m)));
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    ll f = p.second.first, s = p.second.second;
    if (d[f][s] < p.first)
      continue;
    for (auto &e: G[f]) {
      if (s<e.cost)
        continue;
      ll c = min(s-e.cost,(ll)2500);
      if (d[e.to][c] > d[f][s]+e.time) {
        d[e.to][c] = d[f][s]+e.time;
        que.push(P(d[e.to][c], make_pair(e.to, c)));
      }
    }
  }
}


int main() {
  int N, M, S;
  cin >> N >> M >> S;
  int u,v; ll a,b;
  rep(i,M) {
    cin >> u >> v >> a >> b;
    u--; v--;
    G[u].push_back({v,a,b});
    G[v].push_back({u,a,b});
  }
  rep(i,N) {
    cin >> a >> b;
    G[i].push_back({i,-a,b});
  }
  dijkstra(S);
  rep1(i,N-1) {
    ll ans = INF;
    rep(j,2501) {
      ans = min(ans, d[i][j]);
    }
    print(ans);
  }
  return 0;
}
