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
  int N;
  vector<ll> dist;

public:
  const ll INF = 1e18;

  WarshallFloyd(int n) : N(n) {
    dist.assign(N*N,INF);
    rep(i,N)
      dist[i*N+i] = 0;
  }

  void add_edge(int a, int b, ll c) { chmin(dist[a*N+b], c); }

  void add_biedge(int a, int b, ll c) {
    add_edge(a,b,c);
    add_edge(b,a,c);
  }

  bool solve() {
    rep(k,N)
      rep(i,N)
        rep(j,N)
          chmin(dist[i*N+j], dist[i*N+k]+dist[k*N+j]);
    bool flag = true;
    rep(i,N) {
      if (dist[i*N+i] < 0)
        flag = false;
    }
    return flag;
  }

  ll get_dist(int s, int d) { return dist[s*N+d]; }
};


int main() {
  int N,M,Q;
  scan(N,M);
  vector<int> U(M), V(M);
  vector<ll> T(M);
  WarshallFloyd wf(N);
  rep(i,M) {
    scan(U[i], V[i], T[i]);
    U[i]--;
    V[i]--;
    wf.add_biedge(U[i], V[i], T[i]);
  }
  wf.solve();
  scan(Q);
  rep(_,Q) {
    int K;
    ll res = 1e18;
    scan(K);
    vector<int> B(K);
    fore(b,B) {
      scan(b);
      b--;
    }
    sort(all(B));
    do {
      pair<ll,ll> cost = {0,0};
      pair<int,int> p = {0,0};
      rep(i,K) {
        int u,v;
        ll t;
        u = U[B[i]];
        v = V[B[i]];
        t = T[B[i]];
        cost = {
          min(cost.first + wf.get_dist(p.first, v), cost.second + wf.get_dist(p.second, v)) + t,
          min(cost.first + wf.get_dist(p.first, u), cost.second + wf.get_dist(p.second, u)) + t
        };
        p = {u,v};
      }
      cost = {
        cost.first + wf.get_dist(p.first, N-1),
        cost.second + wf.get_dist(p.second, N-1)
      };
      chmin(res, min(cost.first, cost.second));
    } while (next_permutation(all(B)));
    print(res);
  }
  return 0;
}