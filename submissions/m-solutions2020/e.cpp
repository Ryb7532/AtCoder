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
  vector<ll> X(N), Y(N), P(N);
  rep(i,N) {
    cin >> X[i] >> Y[i] >> P[i];
  }
  vector<vector<ll>> SX(1<<N,vector<ll>(N)), SY(1<<N,vector<ll>(N));
  rep(i,1<<N) {
    vector<int> x, y;
    x.push_back(0);
    y.push_back(0);
    rep(j,N) {
      if (i&(1<<j)) {
        x.push_back(X[j]);
        y.push_back(Y[j]);
      }
    }
    sort(all(x));
    sort(all(y));
    x.push_back(1e9);
    y.push_back(1e9);
    rep(j,N) {
      int ix = lower_bound(all(x), X[j]) - x.begin();
      if (ix > 0 && X[j]-x[ix-1] < x[ix]-X[j])
        --ix;
      SX[i][j] = P[j] * (abs(X[j]-x[ix]));
      int iy = lower_bound(all(y), Y[j]) - y.begin();
      if (iy > 0 && Y[j]-y[iy-1] < y[iy]-Y[j])
        --iy;
      SY[i][j] = P[j] * (abs(Y[j]-y[iy]));
    }
  }
  vector<ll> res(N+1,1e18);
  int pow3 = 1;
  rep(_,N) {
    pow3 *= 3;
  }
  rep(i,pow3) {
    int cnt = 0;
    int x = 0, y = 0;
    ll tmp = i;
    rep(i,N) {
      x <<= 1;
      y <<= 1;
      if (tmp%3)
        cnt++;
      if (tmp%3 == 1)
        x += 1;
      if (tmp%3 == 2)
        y += 1;
      tmp /= 3;
    }
    rep(j,N) {
      tmp += min(SX[x][j], SY[y][j]);
    }
    res[cnt] = min(res[cnt], tmp);
  }
  rep(i,N+1) {
    print(res[i]);
  }
  return 0;
}