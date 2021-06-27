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
  int R,C,D;
  cin >> R >> C >> D;
  vvi A(R,vi(C));
  rep(i,R) {
    rep(j,C) {
      cin >> A[i][j];
    }
  }
  int ans = 0;
  rep(i,R) {
    rep(j,C) {
      if ((i+j)%2 != D%2)
        continue;
      if (i+j>D)
        continue;
      ans = max(ans,A[i][j]);
    }
  }
  print(ans);
  return 0;
}
