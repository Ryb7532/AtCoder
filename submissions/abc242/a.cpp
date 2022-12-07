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
  int A,B,C,X;
  cin >> A >> B >> C >> X;
  double res = 0.0;
  if (X <= A)
    res = 1.0;
  else if (X > B)
    res = 0.0;
  else
    res = (double)C / (B-A);
  print(res);
  return 0;
}
