#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()


// Task: Single Source Shortest Path Problem
// Bellman-Ford Algorithm
class BellmanFord {
  const ll INF = 1e9;
  int N, E;
  vector<ll> dist;
  vector<int> src, dst;
  vector<ll> cost;

public:
  BellmanFord(int n) : N(n), dist(N, INF) {}

  void add_edge(int a, int b, ll c) {
    src.push_back(a);
    dst.push_back(b);
    cost.push_back(c);
    E++;
  }

  void add_biedge(int a, int b, ll c, int d=1) {
    add_edge(a,b,c);
    add_edge(b,a,d*c);
  }

  bool solve(int s) {
    dist[s] = 0;
    int cnt = 0;
    bool updated = true;
    while (updated) {
      updated = false;
      cnt++;
      rep(i,E) {
        if (dist[dst[i]] > dist[src[i]]+cost[i]) {
          dist[dst[i]] = dist[src[i]]+cost[i];
          updated = true;
          if (cnt == N)
            return false;
        }
      }
    }
    return true;
  }

  ll &operator[](const int d) { return dist[d]; }
};
