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
  int N;
  cin >> N;
  vec<int> A(N), P(N), X(N);
  int res = 1e9+1;
  rep(i,N) {
    cin >> A[i] >> P[i] >> X[i];
    if (A[i] < X[i])
      res = min(res, P[i]);
  }
  if (res == 1e9+1)
    res = -1;
  print(res);
  return 0;
}
