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
  int A,B,C;
  cin >> A >> B >> C;
  A %= 10;
  B %= 4;
  if (B == 0 || (B == 2 && C != 1)) {
    print((A*A*A*A)%10);
    return 0;
  }
  if (B == 2) {
    print((A*A)%10);
    return 0;
  }
  C %= 2;
  if (B == 1 || C == 0) {
    print(A);
  } else {
    print((A*A*A)%10);
  }
  return 0;
}
