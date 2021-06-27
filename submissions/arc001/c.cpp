#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << a << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
vec<string> bord(8),res(8);
bool can = false;

bool check() {
  rep(i,8) {
    int cnt = 0;
    rep(j,8) {
      if (bord[i][j] == 'Q')
        cnt++;
    }
    if (cnt > 1)
      return false;
  }
  rep(i,8) {
    int cnt = 0;
    rep(j,8) {
      if (bord[j][i] == 'Q')
        cnt++;
    }
    if (cnt > 1)
      return false;
  }
  rep(i,8) {
    int cnt = 0;
    rep(j,8-i) {
      if (bord[i+j][j] == 'Q')
        cnt++;
    }
    if (cnt > 1)
      return false;
  }
  rep(i,8) {
    int cnt = 0;
    rep(j,8-i) {
      if (bord[j][i+j] == 'Q')
        cnt++;
    }
    if (cnt > 1)
      return false;
  }
  rep(i,8) {
    int cnt = 0;
    rep(j,i+1) {
      if (bord[i-j][j] == 'Q')
        cnt++;
    }
    if (cnt > 1)
      return false;
  }
  rep(i,8) {
    int cnt = 0;
    rep(j,8-i) {
      if (bord[7-j][i+j] == 'Q')
        cnt++;
    }
    if (cnt > 1)
      return false;
  }
  return true;
}

void dfs(int x) {
  if (x>=8) {
    if (check()) {
      can = true;
      res = bord;
    }
    return ;
  }
  rep(i,8) {
    if (bord[x][i] == 'Q') {
      dfs(x+1);
      return ;
    }
  }
  rep(i,8) {
    if (bord[x][i] == '.') {
      bool has = false;
      rep(j,8) {
        if (bord[j][i] == 'Q')
          has = true;
      }
      if (has)
        continue;
      bord[x][i] = 'Q';
      if (check())
        dfs(x+1);
      bord[x][i] = '.';
    }
  }
}

int main() {
  rep(i,8) cin >> bord[i];
  if (!check()) {
    print("No Answer");
    return 0;
  }
  dfs(0);
  if (can) {
    rep(i,8) {
      print(res[i]);
    }
  } else {
    print("No Answer");
  }
  return 0;
}
