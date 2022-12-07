#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  cin >> N;
  vec<string> S(N), T(N);
  int sl=N, sr=0, st=N, sb=0, tl=N, tr=0, tt=N, tb=0, sh, sw, th, tw;
  rep(i,N) {
    cin >> S[i];
    bool has = false;
    rep(j,N) {
      if (S[i][j] == '#') {
        has = true;
        sl = min(sl, j);
        sr = max(sr, j);
      }
      if (has) {
        st = min(st, i);
        sb = max(sb, i);
      }
    }
  }
  rep(i,N) {
    cin >> T[i];
    bool has = false;
    rep(j,N) {
      if (T[i][j] == '#') {
        has = true;
        tl = min(tl, j);
        tr = max(tr, j);
      }
      if (has) {
        tt = min(tt, i);
        tb = max(tb, i);
      }
    }
  }
  sh = sb-st+1; sw = sr-sl+1;
  th = tb-tt+1; tw = tr-tl+1;
  if (sh == th && sw == tw) {
    bool check = false;
    bool tmp = true;
    rep(i,sh) {
      rep(j,sw) {
        tmp = tmp && (S[st+i][sl+j] == T[tt+i][tl+j]);
      }
    }
    check = check || tmp;
    tmp = true;
    rep(i,sh) {
      rep(j,sw) {
        tmp = tmp && (S[sb-i][sr-j] == T[tt+i][tl+j]);
      }
    }
    check = check || tmp;
    if (check) {
      print(Yes);
      return 0;
    }
  }
  if (sw == th && sh == tw) {
    bool check = false;
    bool tmp = true;
    rep(i,sh) {
      rep(j,sw) {
        tmp = tmp && (S[st+i][sr-j] == T[tt+j][tl+i]);
      }
    }
    check = check || tmp;
    tmp = true;
    rep(i,sh) {
      rep(j,sw) {
        tmp = tmp && (S[sb-i][sl+j] == T[tt+j][tl+i]);
      }
    }
    check = check || tmp;
    if (check) {
      print(Yes);
      return 0;
    }
  }
  print(No);
  return 0;
}
