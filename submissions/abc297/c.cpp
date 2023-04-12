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
  int H,W;
  cin >> H >> W;
  vector<string> S(H);
  rep(i,H) {
    cin >> S[i];
  }
  rep(i,H) {
    rep(j,W-1) {
      if (S[i][j] == 'T' && S[i][j+1] == 'T') {
        S[i][j] = 'P';
        S[i][j+1] = 'C';
      }
    }
  }
  rep(i,H) {
    print(S[i]);
  }
  return 0;
}
