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
  ll N,M;
  cin >> N >> M;
  vec<pair<ll,ll>> A(M);
  ll res = 0;
  rep(i,M) {
    cin >> A[i].second >> A[i].first;
  }
  sort(all(A));
  rep(i,M) {
    ll a,b;
    a = N;
    b = A[i].second;
    while (b!=0) {
      a %= b;
      swap(a,b);
    }
    if (a==N)
      continue;
    res += A[i].first * (N/a-1)*a;
    N = a;
  }
  if (N!=1)
    res = -1;
  print(res);
  return 0;
}
