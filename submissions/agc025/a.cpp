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
  int N;
  cin >> N;
  int res = 100;
  for (int i=1; i<=N/2; i++) {
    int A=i, B=N-i, sum = 0;
    while (A!=0 || B!=0) {
      sum += A%10 + B%10;
      A /= 10;
      B /= 10;
    }
    res = min(res, sum);
  }
  print(res);
  return 0;
}
