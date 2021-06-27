#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M, T;
ll A[100000];

//Dijkstra (no minus cost path)
#define MAX_V 100000
#define INF 1LL << 50
using Edge = struct{
  int to;
  ll cost;
};
typedef pair<ll, ll> P; //first:dis second:num

ll d[MAX_V][2];
vector<Edge> G[MAX_V][2];

void dijkstra(int s, int id) {
  for (int i=0; i<N; i++)
    d[i][id] = INF;
  d[s][id] = 0;

  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, s));
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v][id] < p.first)
      continue;
    for (auto &e: G[v][id]) {
      if (d[e.to][id] > d[v][id]+e.cost) {
        d[e.to][id] = d[v][id]+e.cost;
        que.push(P(d[e.to][id], e.to));
      }
    }
  }
}

int main() {
  int a, b, c;
  cin >> N >> M >> T;
  for (int i=0; i<N; i++)
    cin >> A[i];
  for (int i=0; i<M; i++) {
    cin >> a >> b >> c;
    a--; b--;
    G[a][0].push_back({b, c});
    G[b][1].push_back({a, c});
  }
  dijkstra(0, 0);
  dijkstra(0, 1);
  ll ans = 0;
  for (int i=0; i<N; i++) {
    ll tc = d[i][0]+d[i][1];
    if (tc > T)
      continue;
    ans = max(ans, A[i]*(T-tc));
  }
  cout << ans << endl;
  return 0;
}
