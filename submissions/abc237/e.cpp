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


//Dijkstra (no minus cost path)
const int MAX_V = 200000;
const ll INF = 1LL << 50;
typedef struct{
  int to;
  ll cost;
} Edge;
typedef pair<ll, int> P; //first:dis second:num

ll d[MAX_V];
vector<vector<Edge>> G(MAX_V);

void dijkstra(int s) {
  fill(d, d+MAX_V, INF);
  d[s] = 0;

  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, s));
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first)
      continue;
    for (auto &e: G[v]) {
      if (d[e.to] > d[v]+e.cost) {
        d[e.to] = d[v]+e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}


int main() {
  int N,M;
  cin >> N >> M;
  vector<ll> H(N);
  rep(i,N) {
    cin >> H[i];
  }
  rep(_,M) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    if (H[u]<H[v])
      swap(u,v);
    G[u].push_back({v,0});
    G[v].push_back({u,H[u]-H[v]});
  }
  dijkstra(0);
  ll res=0;
  rep(i,N) {
    res = max(res, H[0]-H[i]-d[i]);
  }
  print(res);
  return 0;
}
