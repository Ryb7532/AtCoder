#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  string S;
  cin >> S;
  bool hard = true;
  int N = S.size();
  rep(i,N) {
    char c = S[i];
    if (i%2) {
      if (!(c-'A' >= 0 && c-'Z' <= 0))
        hard = false;
    } else {
      if (!(c-'a' >= 0 && c-'z' <= 0))
        hard = false;
    }
  }
  print((hard ? Yes : No));
  return 0;
}
