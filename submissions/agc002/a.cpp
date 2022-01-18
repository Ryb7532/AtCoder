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
  int a,b;
  cin >> a >> b;
  if (a <= 0 && b >= 0) {
    print("Zero");
  } else if (a > 0 || (b-a+1)%2 == 0) {
    print("Positive");
  } else {
    print("Negative");
  }
  return 0;
}
