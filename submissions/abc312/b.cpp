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
  int N,M;
  cin >> N >> M;
  vector<string> S(N);
  rep(i,N) {
    cin >> S[i];
  }
  rep(i,N-8) {
    rep(j,M-8) {
      bool flag = true;
      rep(k,3) {
        rep(l,3) {
          if (S[i+k][j+k] == '.')
            flag = false;
          if (S[i+6+k][j+6+l] == '.')
            flag = false;
        }
      }
      rep(k,4) {
        if (S[i+3][j+k] == '#')
          flag = false;
        if (S[i+k][j+3] == '#')
          flag = false;
        if (S[i+8-k][j+5] == '#')
          flag = false;
        if (S[i+5][j+8-k] == '#')
          flag = false;
      }
      if (flag) {
        print(i+1 << " " << j+1);
      }
    }
  }
  return 0;
}
