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
  vector<vector<int>> A(N, vector<int>(N)), B(N, vector<int>(N));
  rep(i,N) {
    rep(j,N) {
      cin >> A[i][j];
    }
  }
  rep(i,N) {
    rep(j,N) {
      cin >> B[i][j];
    }
  }
  bool flag = false;
  rep(_,4) {
    bool f = true;
    rep(i,N) {
      rep(j,N) {
        if (A[i][j] == 1) {
          if (B[i][j] != 1) {
            f = false;
          }
        }
      }
    }
    if (f)
      flag = true;
    vector<vector<int>> nA(N, vector<int>(N));
    rep(i,N) {
      rep(j,N) {
        nA[j][N-1-i] = A[i][j];
      }
    }
    A = nA;
  }
  printyesno(flag);
  return 0;
}
