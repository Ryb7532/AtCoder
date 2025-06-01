#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()


// Task: Single Source Shortest Path Problem
// Dijkstra (no minus cost path)
class Dijkstra {
  const ll INF = 1e9;
  int N;
  vector<ll> dist;
  using P = pair<ll,int>;
  vector<vector<P>> edge;

public:
  Dijkstra(int n) : N(n), dist(N, INF), edge(N) {}

  void add_edge(int a, int b, ll c) {
    assert(c >= 0);
    edge[a].push_back({c,b});
  }

  void add_biedge(int a, int b, ll c) {
    add_edge(a,b,c);
    add_edge(b,a,c);
  }

  void solve(int s) {
    dist[s] = 0;
    priority_queue<P,vector<P>,greater<P>> q;
    q.push({0,s});
    while (!q.empty()) {
      auto [d,u] = q.top();
      q.pop();
      if (dist[u] < d)
        continue;
      for (auto [c,v]: edge[u]) {
        if (dist[v] > dist[u]+c) {
          dist[v] = dist[u]+c;
          q.push({dist[v],v});
        }
      }
    }
  }

  ll &operator[](const int d) { return dist[d]; }
};
