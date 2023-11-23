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

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  ll s = 0, x = 0, y;
  rep(i,N) {
    cin >> A[i];
    x ^= A[i];
  }
  s = A[0] + A[1];
  x ^= A[0] ^ A[1];
  y = (s-x)/2;
  if (s-x < 0 || ((s-x) & 1) || y & x) {
    print(-1);
    return 0;
  }
  ll a = y, b = y;
  ll k = 1ll << 40;
  while (k != 0) {
    if (x & k) {
      if (a+k <= A[0])
        a += k;
      else
        b += k;
    }
    k >>= 1;
  }
  if (a == 0 || a > A[0])
    a = A[0]+1;
  print(A[0]-a);
  return 0;
}