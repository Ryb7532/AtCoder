#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep1(n) rep2(_,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define out1(a) cout << (a) << endl
#define out2(a,b) cout << (a) << " " << (b) << endl
#define out3(a,b,c) cout << (a) << " " << (b) << " " << (c) << endl
#define print(...) GET_MACRO(__VA_ARGS__,out3,out2,out1)(__VA_ARGS__)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << (f ? Yes : No) << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}

int N,H,W;
vector<int> A, B;
vector<bool> used;
vector<vector<bool>> filled(20, vector<bool>(20, true));

bool dfs() {
  bool f = true;
  int h = H, w = W;
  rep(i,H) {
    rep(j,W) {
      if (f && !filled[i][j]) {
        f = false;
        h = i;
        w = j;
      }
    }
  }
  if (f) return true;
  rep(k,N) {
    if (used[k]) continue;
    rep(2) {
      f = true;
      for (int i=h; i<h+A[k] && f; i++) {
        for (int j=w; j<w+B[k] && f; j++) {
          if (filled[i][j])
            f = false;
        }
      }
      if (f) {
        used[k] = true;
        rep(i,h,h+A[k]) {
          rep(j,w,w+B[k]) {
            filled[i][j] = true;
          }
        }
        if (dfs()) return true;
        rep(i,h,h+A[k]) {
          rep(j,w,w+B[k]) {
            filled[i][j] = false;
          }
        }
        used[k] = false;
      }
      swap(A[k],B[k]);
    }
  }
  return false;
}

int main() {
  cin >> N >> H >> W;
  A.resize(N);
  B.resize(N);
  rep(i,N) {
    cin >> A[i] >> B[i];
  }
  used.assign(N, false);
  rep(i,H) {
    rep(j,W) {
      filled[i][j] = false;
    }
  }
  bool res = dfs();
  printyn(res);
  return 0;
}