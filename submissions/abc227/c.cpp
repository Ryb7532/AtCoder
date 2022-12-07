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
  ll N;
  cin >> N;
  ll res = 0;
  for (ll a=1; a*a*a <= N; a++) {
    for (ll b=a; a*b*b <= N; b++) {
      res += N/(a*b)-b+1;
    }
  }
  print(res);
  return 0;
}
