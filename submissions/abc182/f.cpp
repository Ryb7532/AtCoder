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
#define printall(a) for (auto &e: a) cout << e << " "; cout << endl

int main() {
  int N;
  ll X;
  cin >> N >> X;
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  vector<map<ll,ll>> dp(N+1);
  dp[N][X] = 1;
  rrep(i,N) {
    ll a = A[i];
    ll r = 1e18;
    if (i < N-1)
      r = A[i+1]/a;
    for (auto p: dp[i+1]) {
      ll k = p.first;
      ll v = p.second;
      bool m = k < 0;
      if (m) k *= -1;
      if (k/a < r) {
        ll newk = k%a;
        if (m) newk *= -1;
        dp[i][newk] += v;
      }
      if (k%a && k/a+1 < r) {
        ll newk = k%a-a;
        if (m) newk *= -1;
        dp[i][newk] += v;
      }
    }
  }
  print(dp[0][0]);
  return 0;
}