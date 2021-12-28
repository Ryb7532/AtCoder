#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  cin >> N;
  ll C = 0;
  map<ll,ll> cnt;
  cnt[0]++;
  rep(i,N) {
    ll A;
    cin >> A;
    C = (i%2) ? C+A : C-A;
    cnt[C]++;
  }
  ll res = 0;
  for (auto e: cnt) {
    ll c = e.second;
    res += c*(c-1)/2;
  }
  print(res);
  return 0;
}
