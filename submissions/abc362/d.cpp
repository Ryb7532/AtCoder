#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep1(n) rep2(_,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define out1(a) cout << (a) << endl
#define out2(a,b) cout << (a) << " " << (b) << endl
#define out3(a,b,c) cout << (a) << " " << (b) << " " << (c) << endl
#define print(...) GET_MACRO(__VA_ARGS__,out3,out2,out1)(__VA_ARGS__)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << (f ? Yes : No) << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}

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

  ll &operator[](const int d) { return dist[d]; }
};

int main() {
  int N,M;
  cin >> N >> M;
  Dijkstra dist(2*N);
  rep(i,N) {
    ll A;
    cin >> A;
    dist.add_edge(2*i, 2*i+1, A);
  }
  rep(_,M) {
    int U,V;
    ll B;
    cin >> U >> V >> B;
    U--; V--;
    dist.add_edge(2*U+1, 2*V, B);
    dist.add_edge(2*V+1, 2*U, B);
  }
  dist.solve(0);
  rep(i,1,N) {
    cout << dist[2*i+1] << " ";
  }
  cout << endl;
  return 0;
}