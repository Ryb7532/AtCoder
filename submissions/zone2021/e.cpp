#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

// Task: Single Source Shortest Path Problem
// Dijkstra (no minus cost path)
class Dijkstra {
  int N;
  vector<ll> dist;
  using P = pair<ll,int>;
  vector<vector<P>> edge;

public:
  const ll INF = 1e18;

  Dijkstra(int n) : N(n), dist(N), edge(N) {}

  void add_edge(int a, int b, ll c) {
    assert(c >= 0);
    edge[a].push_back({c,b});
  }

  void add_biedge(int a, int b, ll c) {
    add_edge(a,b,c);
    add_edge(b,a,c);
  }

  void solve(int s) {
    fill(all(dist), INF);
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

  ll get_dist(int d) { return dist[d]; }
};

int main() {
  int H, W;
  cin >> H >> W;
  Dijkstra d(2*H*W);
  vector<vector<ll>> A(H,vector<ll>(W-1)), B(H-1,vector<ll>(W));
  rep(i,H) {
    rep(j,W-1) {
      ll a;
      cin >> a;
      d.add_biedge(i*W+j, i*W+j+1, a);
    }
  }
  rep(i,H-1) {
    rep(j,W) {
      ll b;
      cin >> b;
      d.add_edge(i*W+j, (i+1)*W+j, b);
    }
  }
  rep(i,H) {
    rep(j,W) {
      if (i != 0)
        d.add_edge(H*W+i*W+j, H*W+(i-1)*W+j, 1);
      d.add_edge(i*W+j, H*W+i*W+j, 1);
      d.add_edge(H*W+i*W+j, i*W+j, 0);
    }
  }
  d.solve(0);
  print(d.get_dist(H*W-1));
  return 0;
}