#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int n;
  ll x, m=0, c=0;
  ld e=0.0;
  cin >> n;
  rep(i,n) {
    cin >> x;
    if (x < 0) x = -x;
    m += x;
    e += (ld)x*x;
    c = max(c,x);
  }
  print(m);
  //cout << fixed << setprecision(9) << sqrtl(e) << endl;
  print(fix(9) << sqrtl(e));
  print(c);
  return 0;
}
