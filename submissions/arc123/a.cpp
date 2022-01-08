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
  ll res = 0;
  if (A+C>2*B) {
    res += (A+C-2*B+1)/2;
    B += res;
  }
  if (A+C<2*B) {
    res += 2*B-A-C;
  }
  print(res);
  return 0;
}
