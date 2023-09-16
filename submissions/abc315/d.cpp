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
  vector<vector<int>> cntH(H, vector<int>(26,0)), cntW(W, vector<int>(26,0));
  rep(i,H) {
    string S;
    cin >> S;
    rep(j,W) {
      cntH[i][S[j]-'a']++;
      cntW[j][S[j]-'a']++;
    }
  }
  int rH = H, rW = W;
  bool flag = true;
  while (flag) {
    flag = false;
    vector<int> rmH, rmW;
    rep(i,H) {
      int c = 0;
      rep(k,26) {
        if (cntH[i][k] > 0)
          c++;
      }
      if (c == 1) {
        rep(k,26) {
          if (cntH[i][k] > 1) {
            rmW.push_back(k);
            rH--;
          }
          cntH[i][k] = 0;
        }
      }
    }
    rep(j,W) {
      int c = 0;
      rep(k,26) {
        if (cntW[j][k] > 0)
          c++;
      }
      if (c == 1) {
        rep(k,26) {
          if (cntW[j][k] > 1) {
            rW--;
            rmH.push_back(k);
            cntW[j][k] = 0;
          }
        }
      }
    }
    rep(i,H) {
      for (int c: rmH) {
        cntH[i][c]--;
      }
    }
    rep(j,W) {
      for (int c: rmW) {
        cntW[j][c]--;
      }
    }
    flag = rmH.size() +rmW.size() > 0;
  }
  print(rH * rW);
  return 0;
}