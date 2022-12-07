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
  ll N,K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  ll u = 1e18, l = 1;
  while (u-l > 1) {
    ll mid = (u+l)/2;
    ll sum = 0;
    rep(i,N) {
      sum += min(A[i], mid);
    }
    rep(i,K) {
      sum -= mid;
      if (sum < 0)
        break;
    }
    if (sum < 0) {
      u = mid;
    } else {
      l = mid;
    }
  }
  print(l);
  return 0;
}
