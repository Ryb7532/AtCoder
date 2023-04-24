#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define rrep(i,n) for (int i=(int)(n)-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int N,T;
  cin >> N >> T;
  int cntT = 0;
  vector<int> C(N), R(N);
  rep(i,N) {
    cin >> C[i];
    if (C[i] == T)
      cntT++;
  }
  rep(i,N) {
    cin >> R[i];
  }
  int res = 0;
  int maxR = 0;
  if (cntT == 0)
    T = C[0];
  rep(i,N) {
    if (C[i] == T) {
      if (maxR < R[i]) {
        maxR = R[i];
        res = i+1;
      }
    }
  }
  print(res);
  return 0;
}
