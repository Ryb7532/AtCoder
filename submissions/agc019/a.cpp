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
  vector<ll> C(4);
  ll N;
  rep(i,4) {
    cin >> C[i];
  }
  cin >> N;
  ll min_2l = C[3], min_1l = C[2];
  ll pow = 1;
  for (int i=2; i>=0; i--) {
    min_1l = min(min_1l, C[i]*pow);
    pow *= 2;
    min_2l = min(min_2l, C[i]*pow);
  }
  ll res = N/2 * min_2l;
  if (N%2) {
    res += min_1l;
  }
  print(res);
  return 0;
}
