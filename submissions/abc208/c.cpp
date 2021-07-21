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
  ll N,K;
  cin >> N >> K;
  vec<pair<ll,ll>> a(N);
  rep(i,N) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(all(a));
  map<ll,ll> m;
  rep(i,N) {
    m[a[i].second] = i;
  }
  rep(i,N) {
    ll res;
    res = K/N;
    if (K%N>m[i])
      res++;
    print(res);
  }
  return 0;
}
