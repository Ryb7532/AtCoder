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
  bool y = false;
  for (char c: S) {
    if (y) {
      if (c-'0'<=2)
        cout << '-';
      else if (c-'0'>=7)
        cout << '+';
      cout << endl;
    } else if (c == '.') {
      y = true;
    } else {
      cout << c;
    }
  }
  return 0;
}
