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

int main() {
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  vector<char> U(N);
  rep(i,N) {
    cin >> X[i] >> Y[i] >> U[i];
  }
  string d = "ULDR";
  map<char,char> rotated;
  rep(i,4) {
    rotated[d[i]] = d[(i+1)%4];
  }
  const int MAX = 2e5;
  const int INF = 1e9;
  auto rotate = [&]() {
    rep(i,N) {
      int tmp = X[i];
      X[i] = MAX - Y[i];
      Y[i] = tmp;
      U[i] = rotated[U[i]];
    }
  };
  int res = INF;
  rep(_,2) {
    vector<vector<pair<int,char>>> x(MAX+1);
    rep(i,N) {
      if (U[i] == 'U' || U[i] == 'D')
        x[X[i]].push_back({Y[i],U[i]});
    }
    rep(i,MAX+1) {
      if (x[i].size() <= 1)
        continue;
      sort(all(x[i]));
      int py = -1;
      char pu = '#';
      for (auto [y,u]: x[i]) {
        if (pu == 'U' && u == 'D') {
          res = min(res, (y-py)*5);
        }
        py = y;
        pu = u;
      }
    }
    rotate();
  }
  rep(_,4) {
    vector<vector<pair<int,char>>> xy(2*MAX+1);
    rep(i,N) {
      if (U[i] == 'U' || U[i] == 'R')
        xy[X[i]+Y[i]].push_back({Y[i],U[i]});
    }
    rep(i,2*MAX+1) {
      if (xy[i].size() <= 1)
        continue;
      sort(all(xy[i]));
      int py = -1;
      char pu = '#';
      for (auto [y,u]: xy[i]) {
        if (pu == 'U' && u == 'R') {
          res = min(res, (y-py)*10);
        }
        py = y;
        pu = u;
      }
    }
    rotate();
  }
  if (res == INF)
    print("SAFE");
  else
    print(res);
  return 0;
}