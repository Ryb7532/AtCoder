#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl

int main() {
  int N,M;
  cin >> N >> M;
  vector<ll> L(N);
  ll maxL = 0;
  rep(i,N) {
    cin >> L[i];
    maxL = max(maxL, L[i]);
  }
  ll l = maxL-1, u = 1e18;
  while (u-l > 1) {
    ll m = (u+l)/2;
    ll line = 1, right = -1;
    rep(i,N) {
      if (right + 1 + L[i] > m) {
        line++;
        right = L[i];
      } else {
        right += 1 + L[i];
      }
    }
    if (line > M)
      l = m;
    else
      u = m;
  }
  print(u);
  return 0;
}