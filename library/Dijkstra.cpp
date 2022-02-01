#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


//Dijkstra (no minus cost path)
const int MAX_V = 1000;
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
