#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"

ll extGCD(ll a, ll b, ll &x, ll &y) {
  if (b==0) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = extGCD(b, a%b, y, x);
  y -= a/b*x;
  return d;
}


int main() {
  int T;
  ll N,S,K;
  cin >> T;
  rep(t,T) {
    cin >> N >> S >> K;
    ll x, y;
    ll g = extGCD(N, K, x, y);
    if (S%g != 0) {
      print(-1);
    } else {
      x *= S/g;
      y *= S/g;
      N /= g;
      if (y>0)
        y = (y%N) - N;
      ll res = -y;
      res %= N;
      print(res);
    }
  }
  return 0;
}
