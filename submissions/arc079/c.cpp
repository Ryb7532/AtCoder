#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << a << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int main() {
  ll N;
  cin >> N;
  vec<ll> a(N);
  ll sum = 0;
  rep(i,N) {
    cin >> a[i];
    sum += a[i];
  }
  sum -= N*(N-1);
  sum = max(sum,(ll)0);
  ll ans = sum;
  rep(i,N) a[i] += sum;
  rep(i,N) {
    ll t = a[i]/(N+1);
    t = min(t,sum);
    a[i] -= t*(N+1);
    sum -= t;
  }
  while (1) {
    ll cnt = 0;
    rep(i,N) {
      cnt += a[i]/N;
    }
    if (cnt == 0)
      break;
    ans += cnt;
    rep(i,N) {
      if (a[i]<N)
        a[i] += cnt;
      else {
        ll t = a[i]/N;
        a[i] -= t*(N+1);
        a[i] += cnt;
      }
    }
  }
  print(ans);
  return 0;
}
