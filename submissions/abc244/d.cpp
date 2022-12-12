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
  char S[3], T[3];
  rep(i,3) {
    cin >> S[i];
  }
  rep(i,3) {
    cin >> T[i];
  }
  int same = 0;
  rep(i,3) {
    same += S[i] == T[i];
  }
  print((same == 1 ? No : Yes));
  return 0;
}
