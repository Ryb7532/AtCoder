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

vector<vector<int>> C(3, vector<int>(3));
vector<bool> used(9, false);
ll pat = 0;

bool check(int i) {
  int x = i%3, y = i/3;
  int cnt = 0;
  bool flag = false;
  rep(i,3) {
    if (used[x+i*3]) {
      cnt++;
      if (C[x][y] == C[x][i])
        flag = true;
    }
  }
  if (cnt == 1 && flag)
    return true;
  cnt = 0;
  flag = false;
  rep(i,3) {
    if (used[i+y*3]) {
      cnt++;
      if (C[x][y] == C[i][y])
        flag = true;
    }
  }
  if (cnt == 1 && flag)
    return true;
  if (x == y) {
    cnt = 0;
    flag = false;
    rep(i,3) {
      if (used[i+i*3]) {
        cnt++;
        if (C[x][y] == C[i][i])
          flag = true;
      }
    }
    if (cnt == 1 && flag)
      return true;
  }
  if (x+y == 2) {
    cnt = 0;
    flag = false;
    rep(i,3) {
      if (used[i+(2-i)*3]) {
        cnt++;
        if (C[x][y] == C[i][2-i])
          flag = true;
      }
    }
    if (cnt == 1 && flag)
      return true;
  }
  return false;
}

void dfs(int n) {
  if (n == 9) {
    pat++;
    return ;
  }
  rep(i,9) {
    if (used[i])
      continue;
    if (check(i))
      continue;
    used[i] = true;
    dfs(n+1);
    used[i] = false;
  }
}

int main() {
  rep(i,3) {
    rep(j,3) {
      cin >> C[i][j];
    }
  }
  dfs(0);
  print(fix(10) << pat/362880.0);
  return 0;
}