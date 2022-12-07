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
  ll A,B,C;
  cin >> A >> B >> C;
  vector<ll> p(3);
  p[0] = A*B;
  p[1] = B*C;
  p[2] = C*A;
  sort(all(p));
  if (A%2==0 || B%2==0 || C%2==0) {
    print(0);
    return 0;
  }
  print(p[0]);
  return 0;
}
