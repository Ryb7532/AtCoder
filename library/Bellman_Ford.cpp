#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

// Task: Single Source Shortest Path Problem
// Bellman-Ford Algorithm
const int MAX_V = 1000;
const ll INF = 1e9;
typedef struct{
  int from;
  int to;
  ll cost;
} Edge;

int V, E;
ll d[MAX_V];
vector<Edge> edge;

bool bellman_ford(int s) {
  fill(d, d+V, INF);
  d[s] = 0;
  rep(i,V) {
    rep(j,E) {
      Edge e = edge[j];
      if (d[e.to] > d[e.from]+e.cost) {
        d[e.to] = d[e.from] + e.cost;
        if (i == V-1)
          return true;
      }
    }
  }
  return false;
}
