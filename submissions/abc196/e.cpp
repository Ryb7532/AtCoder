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

const ll INF = 1LL << 50;

int main() {
  int N,Q;
  cin >> N;
  vec<int> a(N),t(N);
  rep(i,N) {
    cin >> a[i] >> t[i];
  }
  vec<ll> f(2);
  ll y = 0;
  f[0] = -INF;
  f[1] = INF;
  rep(i,N) {
    if (t[i]==1) {
      y += a[i];
    } else if (t[i]==2) {
      f[0] = max(f[0],a[i]-y);
      f[1] = max(f[1],a[i]-y);
    } else {
      f[0] = min(f[0],a[i]-y);
      f[1] = min(f[1],a[i]-y);
    }
  }
  cin >> Q;
  ll x;
  rep(_,Q) {
    cin >> x;
    if (x<f[0])
      print(f[0]+y);
    else if (x<f[1])
      print(x+y);
    else
      print(f[1]+y);
  }
  return 0;
}
