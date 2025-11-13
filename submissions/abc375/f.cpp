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
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define printyn(f) cout << ((f) ? "Yes" : "No") << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}
void print() {cout << endl;}
template<typename Arg, typename... Args> void print(const Arg a, const Args... b) {
  cout << a;
  (cout << ... << (cout << ' ', b)) << endl;
}
template<class... T> void scan(T&... a) {(cin >> ... >> a);}

// Task: All Pair Shortest Path Problem
// Warshall-Floyd Algorithm
class WarshallFloyd {
  const ll INF = 1e18;
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

  void update(int s, int d, ll c) {
    chmin(dist[s*N+d], c);
    chmin(dist[d*N+s], c);
    rep(x, N) {
      rep(y, N) {
        chmin(dist[x*N+y], dist[x*N+s]+dist[s*N+d]+dist[d*N+y]);
        chmin(dist[x*N+y], dist[x*N+d]+dist[d*N+s]+dist[s*N+y]);
      }
    }
  }

  ll get_dist(int s, int d) { return dist[s*N+d]; }
};

int main() {
  int n, m, q;
  scan(n, m, q);
  vector<int> A(m), B(m);
  vector<ll> C(m);
  vector<bool> added(m, true);
  vector<pair<int,int>> add, query;
  rep(i,m) {
    scan(A[i], B[i], C[i]);
    A[i]--; B[i]--;
  }
  rep(i,q) {
    int t; scan(t);
    if (t == 1) {
      int x; scan(x); x--;
      added[x] = false;
      add.emplace_back(i, x);
    } else {
      int s, d; scan(s, d);
      s--; d--;
      query.emplace_back(s, d);
    }
  }
  WarshallFloyd wf(n);
  rep(i,m) {
    if (added[i])
      wf.add_biedge(A[i], B[i], C[i]);
  }
  wf.solve();
  vector<ll> res;
  rrep(i,q) {
    if (!add.empty() && add.back().first == i) {
      int x = add.back().second;
      wf.update(A[x], B[x], C[x]);
      add.pop_back();
    } else {
      auto [s, d] = query.back();
      query.pop_back();
      ll dist = wf.get_dist(s, d);
      if (dist < 1e18)
        res.push_back(dist);
      else
        res.push_back(-1);
    }
  }
  rrep(i,(int)res.size()) {
    print(res[i]);
  }
  return 0;
}