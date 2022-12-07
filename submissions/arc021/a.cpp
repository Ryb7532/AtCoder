#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  vvi A(4,vi(4));
  rep(i,4) {
    rep(j,4) {
      cin >> A[i][j];
    }
  }
  rep(i,4) {
    rep(j,4) {
      if (i<3) {
        if (A[i][j] == A[i+1][j]) {
          print("CONTINUE");
          return 0;
        }
      }
      if (j<3) {
        if (A[i][j] == A[i][j+1]) {
          print("CONTINUE");
          return 0;
        }
      }
    }
  }
  print("GAMEOVER");
  return 0;
}
