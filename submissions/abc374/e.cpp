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

int main() {
  int N;
  ll X;
  scan(N, X);
  vector<ll> A(N), B(N), P(N), Q(N);
  rep(i,N) scan(A[i], P[i], B[i], Q[i]);
  ll l = 0, r = 1e10;
  while (r - l > 1) {
    ll m = (l + r) / 2;
    ll cost = 0;
    rep(i, N) {
      ll c = 1e10;
      rep(j, B[i]) {
        chmin(c, j * P[i] + (max(0LL, m - A[i] * j) + B[i] - 1) / B[i] * Q[i]);
      }
      rep(j, A[i]) {
        chmin(c, j * Q[i] + (max(0LL, m - B[i] * j) + A[i] - 1) / A[i] * P[i]);
      }
      cost += c;
    }
    if (cost <= X) l = m;
    else r = m;
  }
  print(l);
  return 0;
}