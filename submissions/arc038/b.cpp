#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  int H,W;
  cin >> H >> W;
  string S[H+1];
  rep(i,H) {
    cin >> S[i];
    S[i].push_back('#');
  }
  rep(i,W+1) {
    S[H].push_back('#');
  }
  bool win[H+1][W+1];
  rep(i,H+1) {
    fill(win[i],win[i]+W+1,true);
  }
  repr(i,H,0) {
    repr(j,W,0) {
      if (S[i][j] == '#') {
        continue;
      }
      bool tmp = false;
      tmp = tmp || !win[i][j+1];
      tmp = tmp || !win[i+1][j+1];
      tmp = tmp || !win[i+1][j];
      win[i][j] = tmp;
    }
  }
  print(win[0][0]?"First":"Second");
  return 0;
}
