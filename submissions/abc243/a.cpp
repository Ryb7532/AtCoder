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
  int V, A, B, C;
  cin >> V >> A >> B >> C;
  int sum = A + B + C;
  V %= sum;
  if (V < A) {
    print("F");
  } else if (V < A+B) {
    print("M");
  } else {
    print("T");
  }
  return 0;
}
