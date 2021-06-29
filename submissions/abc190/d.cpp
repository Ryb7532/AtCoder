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
  N *= 2;
  int res = 0;
  res += 2;
  for (int n=2; n<sqrt((double)N+0.01); n++) {
    if (N%n != 0)
      continue;
    ll M = N/n;
    if ((M-n+1)%2 == 0)
      res += 2;
  }
  print(res);
  return 0;
}
