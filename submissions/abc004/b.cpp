#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  string S[4][4];
  rep(i, 4) {
    rep(j, 4) {
      cin >> S[i][j];
    }
  }
  repr(i, 4, 0) {
    cout << S[i][3];
    repr(j, 3, 0) {
      cout << " " << S[i][j];
    }
    cout << endl;
  }
  return 0;
}
