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
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

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
  ll N,M,K;
  cin >> N >> M >> K;
  ll g = GCD(N,M).g;
  N /= g;
  M /= g;
  ll k = (K-1)/(N+M-2);
  K -= k * (N+M-2);
  ll l = -1, r = N*M;
  while (r-l > 1) {
    ll m = (r+l)/2;
    if (m/N + m/M < K)
      l = m;
    else
      r = m;
  }
  print((N*M*k+r)*g);
  return 0;
}