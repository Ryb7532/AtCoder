#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  vec<ll> XY(2);
  vec<ll> ABC(3);
  rep(i,2) {
    cin >> XY[i];
  }
  rep(j,3) {
    cin >> ABC[j];
  }
  bool check = false;
  rep(i,2) {
    ll X = XY[i], Y = XY[(i+1)%2];
    vec<ll> y(3);
    ll sum = 0;
    rep(j,3) {
      y[j] = (ABC[j]+X-1)/X;
      sum += y[j];
    }
    if (sum <= Y)
      check = true;
    rep(j,3) {
      ll x_0, x_1;
      Y -= y[j];
      if (Y > 0){
        x_0 = (ABC[(j+1)%3]+Y-1)/Y;
        x_1 = (ABC[(j+2)%3]+Y-1)/Y;
        if (x_0 + x_1 <= X)
          check = true;
      }
      Y += y[j];
    }
  }
  print((check ? Yes : No));
  return 0;
}
