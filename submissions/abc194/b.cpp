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
  vec<int> A(N), B(N);
  rep(i,N)
    cin >> A[i] >> B[i];
  int res = 1e9;
  rep(i,N) {
    rep(j,N) {
      if (i==j)
        res = min(res, A[i]+B[i]);
      else
        res = min(res, max(A[i], B[j]));
    }
  }
  print(res);
  return 0;
}
