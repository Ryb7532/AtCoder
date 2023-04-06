#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int N;
  cin >> N;
  vector<int> X(5*N);
  rep(i,5*N) {
    cin >> X[i];
  }
  sort(all(X));
  ld res = 0;
  for (int i=N; i<4*N; i++) {
    res += X[i];
  }
  print(fix(10) << res/3/N);
  return 0;
}
