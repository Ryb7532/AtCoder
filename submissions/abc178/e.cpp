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
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  cin >> N;
  vec<ll> plus(N),minus(N);
  rep(i,N) {
    ll x,y;
    cin >> x >> y;
    plus[i] = x+y;
    minus[i] = x-y;
  }
  sort(all(plus));
  sort(all(minus));
  ll ans = 0;
  ans = max(ans,abs(plus[N-1]-plus[0]));
  ans = max(ans,abs(minus[N-1]-minus[0]));
  print(ans);
  return 0;
}
