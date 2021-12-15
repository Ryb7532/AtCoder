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
  int K;
  cin >> K;
  int res = 0;
  for (int a=1; a*a*a<=K; a++) {
    for (int b=a; a*b*b<=K; b++) {
      for (int c=b; a*b*c<=K; c++) {
        int d = (a==b) + (b==c) + (c==a);
        if (d == 3) {
          res++;
        } else if (d == 1) {
          res += 3;
        } else {
          res += 6;
        }
      }
    }
  }
  print(res);
  return 0;
}
