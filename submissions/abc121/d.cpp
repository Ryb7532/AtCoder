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
  ll A,B;
  cin >> A >> B;
  ll res;
  if (A%2) {
    ll S = B-A;
    if (B%2) {
      res = A^((S/2)%2);
    } else {
      res = A^B^((S/2)%2);
    }
  } else {
    ll S = B-A+1;
    if (B%2) {
      res = (S/2)%2;
    } else {
      res = B^((S/2)%2);
    }
  }
  print(res);
  return 0;
}
