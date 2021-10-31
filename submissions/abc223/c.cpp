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
  int N;
  cin >> N;
  vec<double> A(N), B(N), T(N);
  double time = 0;
  rep(i,N) {
    cin >> A[i] >> B[i];
    T[i] = A[i]/B[i];
    time += T[i];
  }
  time /= 2;
  double res = 0;
  rep(i,N) {
    if (time > T[i]) {
      time -= T[i];
      res += A[i];
    } else {
      res += B[i]*time;
      break;
    }
  }
  print(fix(15) << res);
  return 0;
}
