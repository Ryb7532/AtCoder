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
  ll A,B;
  cin >> A >> B;
  while (A != 0 && B != 0) {
    if (A%10 + B%10 > 9) {
      print("Hard");
      return 0;
    }
    A /= 10;
    B /= 10;
  }
  print("Easy");
  return 0;
}
