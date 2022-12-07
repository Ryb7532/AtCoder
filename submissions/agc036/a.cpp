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
  ll S;
  cin >> S;
  ll m = 1e9;
  ll a,b;
  a = S/m;
  b = S%m;
  if (b!=0) {
    b = m-b;
    a++;
  }
  print(0 << ' ' << 0 << ' ' << m << ' ' << 1 << ' ' << b << ' ' << a);
  return 0;
}
