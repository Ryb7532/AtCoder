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
  vector<int> H(2), W(2);
  vector<vector<string>> AB(2);
  rep(k,2) {
    int h,w,t,b,r,l;
    cin >> h >> w;
    vector<string> S(h);
    t = 0; b = h-1;
    r = 0; l = w-1;
    rep(i,h) {
      cin >> S[i];
      rep(j,w) {
        if (S[i][j] == '#') {
          t = max(t, i+1);
          b = min(b, i);
          r = max(r, j+1);
          l = min(l, j);
        }
      }
    }
    H[k] = max(0,t-b);
    W[k] = max(0,r-l);
    rep(i,H[k]) {
      string T;
      rep(j,W[k])
        T.push_back(S[i+b][j+l]);
      AB[k].push_back(T);
    }
  }
  int Hx,Wx;
  cin >> Hx >> Wx;
  vector<string> X(Hx);
  rep(i,Hx) {
    cin >> X[i];
  }
  bool res = false;
  rep(ha,Hx-H[0]+1) {
    rep(wa, Wx-W[0]+1) {
      rep(hb,Hx-H[1]+1) {
        rep(wb,Wx-W[1]+1) {
          vector<vector<int>> black(Hx, vector<int>(Wx, 0));
          rep(i,H[0]) {
            rep(j,W[0]) {
              if (AB[0][i][j] == '#')
                black[i+ha][j+wa]++;
            }
          }
          rep(i,H[1]) {
            rep(j,W[1]) {
              if (AB[1][i][j] == '#')
                black[i+hb][j+wb]++;
            }
          }
          bool flag = true;
          rep(i,Hx) {
            rep(j,Wx) {
              if (X[i][j] == '.' && black[i][j] == 0)
                continue;
              if (X[i][j] == '#' && black[i][j] > 0)
                continue;
              flag = false;
            }
          }
          if (flag)
            res = true;
        }
      }
    }
  }
  printyesno(res);
  return 0;
}
