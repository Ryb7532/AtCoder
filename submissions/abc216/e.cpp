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


int main() {
  int N;
  ll K;
  cin >> N >> K;
  vec<ll> A(N);
  ll maxA = 0;
  rep(i,N) {
    cin >> A[i];
    maxA = max(maxA, A[i]);
  }
  ll l = 0, u = maxA+1;
  while (u-l > 1) {
    ll mid = (l+u)/2;
    ll cnt = 0;
    rep(i,N) {
      cnt += max((ll)0, A[i]-mid+1);
    }
    if (cnt >= K)
      l = mid;
    else
      u = mid;
  }
  ll res = 0;
  rep(i,N) {
    if (A[i]<l)
      continue;
    K -= A[i]-l;
    res += (A[i]+l+1)*(A[i]-l)/2;
  }
  res += K*l;
  print(res);
  return 0;
}
