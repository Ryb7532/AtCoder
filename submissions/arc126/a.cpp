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
  int T;
  cin >> T;
  rep(_,T) {
    ll A,B,C;
    ll res = 0;
    cin >> A >> B >> C;
    if (B/2 >= A/2+C) {
      res = A/2+C;
    } else {
      res = B/2;
      if (C <= res) {
        B -= 2*C;
        A -= (B/2)*2;
        res += A/5;
      } else {
        C -= B/2;
        if (C/2 <= A) {
          res += C/2;
          A -= C/2;
          A += (C%2)*2;
          res += A/5;
        } else {
          res += A;
        }
      }
    }
    print(res);
  }
  return 0;
}
