#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
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
  int T;
  cin >> T;
  rep(_,T) {
    ll N;
    cin >> N;
    if (N%2 == 1) {
      print("Odd");
    } else if (N%4 == 0) {
      print("Even");
    } else {
      print("Same");
    }
  }
  return 0;
}
