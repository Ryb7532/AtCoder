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

// Task: Compute GCD(a,b)(=g) and a particular solution of a * x + b * y = g
// Extended Euclidean Algorithm
struct GCD {
  ll x,y,g;

  void solve(ll a, ll b) {
    if (b == 0) {
      x = 1, y = 0;
      g = a;
      return ;
    }
    solve(b, a%b);
    swap(x,y);
    y -= a/b*x;
  }

  GCD(ll a=0, ll b=0) { solve(a,b); }
};

int main() {
  int N;
  scan(N);
  vector<int> P(N), A(N), res(N);
  vector<bool> visited(N,false);
  rep(i,N) {
    scan(P[i]);
    P[i]--;
  }
  rep(i,N) {
    scan(A[i]);
  }
  map<int, int, greater<int>> decided;
  GCD gcd;
  rep(i,N) {
    if (visited[i]) continue;
    vector<int> cycle = {i};
    visited[i] = true;
    int cur = P[i];
    while (!visited[cur]) {
      cycle.push_back(cur);
      visited[cur] = true;
      cur = P[cur];
    }
    int len = cycle.size();
    vector<int> cand;
    rep(j,len) {
      bool ok = true;
      fore(d, decided) {
        auto [d_len, d_idx] = d;
        gcd.solve(len, d_len);
        if (abs(j - d_idx) % gcd.g != 0) {
          ok = false;
          break;
        }
      }
      if (ok) cand.push_back(j);
    }
    int best = 1e6;
    int best_idx = -1;
    fore(j, cand) {
      if (best > A[cycle[j]]) {
        best = A[cycle[j]];
        best_idx = j;
      }
    }
    rep(j,len) {
      res[cycle[j]] = A[cycle[(j + best_idx) % len]];
    }
    decided[len] = best_idx;
  }
  printall(res);
  return 0;
}