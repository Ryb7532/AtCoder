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
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

vector<vector<string>> P(3, vector<string>(4));
vector<vector<int>> G(10, vector<int>(10));
bool res = false;

void rot(int id) {
  vector<string> tmp = P[id];
  rep(x,4) {
    rep(y,4) {
      P[id][3-y][x] = tmp[x][y];
    }
  }
}

void solve(int p) {
  if (p == 3) {
    rep(x,4) {
      rep(y,4) {
        if (G[3+x][3+y] != 1)
          return ;
      }
    }
    res = true;
    return ;
  }
  rep(h,7) {
    rep(w,7) {
      bool flag = true;
      rep(x,4) {
        rep(y,4) {
          if (P[p][x][y] == '#')
            G[h+x][w+y]++;
          if (G[h+x][w+y] > 1)
            flag = false;
        }
      }
      if (flag)
        solve(p+1);
      rep(x,4) {
        rep(y,4) {
          if (P[p][x][y] == '#')
            G[h+x][w+y]--;
        }
      }
    }
  }
}

int main() {
  rep(i,3) {
    rep(j,4) {
      cin >> P[i][j];
    }
  }
  rep(x,10) {
    rep(y,10) {
      if (x < 3 || x >= 7 || y < 3 || y >= 7)
        G[x][y] = 1;
    }
  }
  rep(a0,4) {
    rep(a1,4) {
      solve(0);
      rot(1);
    }
    rot(2);
  }
  printyesno(res);
  return 0;
}