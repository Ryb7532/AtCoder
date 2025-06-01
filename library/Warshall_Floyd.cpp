#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)

// Task: All Pair Shortest Path Problem
// Warshall-Floyd Algorithm
class WarshallFloyd {
  const ll INF = 1e9;
  int N;
  vector<ll> dist;

public:
  WarshallFloyd(int n) : N(n), dist(N*N,INF) {
    rep(i,N)
      dist[i*N+i] = 0;
  }

  void add_edge(int a, int b, ll c) { dist[a*N+b] = c; }

  void add_biedge(int a, int b, ll c, int d=1) {
    add_edge(a,b,c);
    add_edge(b,a,d*c);
  }

  bool solve() {
    rep(k,N)
      rep(i,N)
        rep(j,N)
          dist[i*N+j] = min(dist[i*N+j], dist[i*N+k]+dist[k*N+j]);
    bool flag = true;
    rep(i,N) {
      if (dist[i*N+i] < 0)
        flag = false;
    }
    return flag;
  }

  ll get_dist(int s, int d) { return dist[s*N+d]; }
};
