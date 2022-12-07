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
  ll N,W,S,T,P;
  cin >> N >> W;
  map<ll,ll> m;
  rep(i,N) {
    cin >> S >> T >> P;
    S--;
    T--;
    m[S] += P;
    m[T] -= P;
  }
  ll res = 0, sum = 0;
  for (auto &e: m) {
    sum += e.second;
    res = max(res,sum);
  }
  print(((res>W) ? No : Yes));
  return 0;
}
