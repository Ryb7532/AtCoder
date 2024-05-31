#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<int>> A(H, vector<int>(W)), B(H, vector<int>(W));
  rep(i,H) {
    rep(j,W) {
      cin >> A[i][j];
    }
  }
  rep(i,H) {
    rep(j,W) {
      cin >> B[i][j];
    }
  }
  int res = 1e9;
  vector<int> orderH(H);
  rep(i,H)
    orderH[i] = i;
  do {
    int swapH = 0;
    set<int> usedH;
    rep(i,H) {
      swapH += distance(usedH.lower_bound(orderH[i]), usedH.end());
      usedH.insert(orderH[i]);
    }
    vector<int> orderW(W);
    rep(i,W)
      orderW[i] = i;
    do {
      int swapW = 0;
      set<int> usedW;
      rep(j,W) {
        swapW += distance(usedW.lower_bound(orderW[j]), usedW.end());
        usedW.insert(orderW[j]);
      }
      bool check = true;
      rep(i,H) {
        rep(j,W) {
          check = check && A[orderH[i]][orderW[j]] == B[i][j];
        }
      }
      if (check) {
        chmin(res, swapH+swapW);
      }
    } while (next_permutation(all(orderW)));
  } while (next_permutation(all(orderH)));
  if (res == 1e9)
    res = -1;
  print(res);
  return 0;
}