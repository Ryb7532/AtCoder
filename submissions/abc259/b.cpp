#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
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
  ld a, b, d;
  cin >> a >> b >> d;
  ld l = sqrt(a*a+b*b);
  ld theta = atan2l(b,a);
  theta += d * M_PI / 180;
  print(fix(10) << l * cos(theta) << " " << l * sin(theta));
  return 0;
}
