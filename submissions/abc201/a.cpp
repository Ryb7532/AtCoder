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
  vec<int> A(3);
  int sum = 0;
  rep(i,3) {
    cin >> A[i];
    sum += A[i];
  }
  bool check = false;
  rep(i,3) {
    if (sum == 3*A[i])
      check = true;
  }
  print((check ? Yes : No));
  return 0;
}
