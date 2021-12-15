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
  ll B,C;
  cin >> B >> C;
  ll res = 0;
  if (C == 1) {
    res = 2;
    if (B == 0)
      res--;
    print(res);
    return 0;
  }
  ll a = C/2, b = (C-1)/2, c = (C-2)/2;
  if (B == 0) {
    res++;
    res += a + b;
  } else if (B < 0) {
    res += 2;
    res += a + b;
    if (-B <= b) {
      res += 2 * -B - 1;
    } else {
      res += b + c;
    }
  } else {
    res += 2;
    res += b + c;
    if (B <= a) {
      res += 2 * B - 1;
    } else {
      res += a + b;
    }
  }
  print(res);
  return 0;
}
