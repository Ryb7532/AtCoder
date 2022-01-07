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
  int N;
  cin >> N;
  vector<ld> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  sort(all(A));
  ld opt = A[N/2]/2;
  ld res = 0;
  rep(i,N) {
    res += opt + A[i] - min(A[i], 2*opt);
  }
  print(fix(9) << res/N);
  return 0;
}
