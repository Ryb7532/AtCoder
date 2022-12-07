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
  ll N;
  cin >> N;
  int A;
  map<ll,ll> m;
  rep(i,N) {
    cin >> A;
    m[A]++;
  }
  ll res = N*(N-1)/2;
  for (auto &e: m) {
    res -= e.second*(e.second-1)/2;
  }
  print(res);
  return 0;
}
