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
  ll N,X,M;
  cin >> N >> X >> M;
  vec<int> A(M,0);
  vec<ll> S(M,0);
  ll ans = 0,cnt = 1;
  while (N > 0) {
    N--;
    ans += X;
    if (A[X] != 0)
      break;
    A[X] = cnt;
    cnt++;
    S[X] = ans;
    X = (X*X)%M;
  }
  if (X != 0 && N > 0) {
    ll l = cnt-A[X];
    ans += N/l * (ans-S[X]);
    N %= l;
    while (N > 0) {
      N--;
      X = (X*X)%M;
      ans += X;
    }
  }
  print(ans);
  return 0;
}
