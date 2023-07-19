#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
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
  int t = 0, b = H, r = 0, l = W;
  rep(i,H) {
    cin >> S[i];
    rep(j,W) {
      if (S[i][j] == '#') {
        t = max(t, i);
        b = min(b, i);
        r = max(r, j);
        l = min(l, j);
      }
    }
  }
  int x = 0, y = 0;
  rep(i,b,t+1) {
    rep(j,l,r+1) {
      if (S[i][j] == '.') {
        x = i+1;
        y = j+1;
      }
    }
  }
  print(x << ' ' << y);
  return 0;
}
