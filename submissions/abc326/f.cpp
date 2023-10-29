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
  int XY[2];
  cin >> N >> XY[1] >> XY[0];
  vector<vector<ll>> A(4);
  int j = 0;
  rep(i,N) {
    ll a;
    cin >> a;
    A[j].push_back(a);
    j++;
    j %= 4;
  }
  vector<vector<set<ll>>> SS(4);
  rep(i,4) {
    int n = A[i].size();
    SS[i].resize(n+1);
    SS[i][0].insert(0);
    rep(j,n) {
      for (ll s: SS[i][j]) {
        SS[i][j+1].insert(s-A[i][j]);
        SS[i][j+1].insert(s+A[i][j]);
      }
    }
  }
  vector<vector<int>> D(4);
  bool flag = true;
  rep(i,2) {
    int n0 = A[i].size(), n1 = A[i+2].size();
    D[i].resize(n0);
    D[i+2].resize(n1);
    ll a0 = 1e18, a1 = 1e18;
    for (ll s: SS[i][n0]) {
      if (SS[i+2][n1].find(XY[i]-s) != SS[i+2][n1].end()) {
        a0 = s;
        a1 = XY[i]-s;
        break;
      }
    }
    if (a0 == 1e18) {
      flag = false;
      break;
    }
    rrep(j,n0) {
      if (SS[i][j].find(a0-A[i][j]) != SS[i][j].end()) {
        a0 -= A[i][j];
        D[i][j] = i;
      } else {
        a0 += A[i][j];
        D[i][j] = i+2;
      }
    }
    rrep(j,n1) {
      if (SS[i+2][j].find(a1-A[i+2][j]) != SS[i+2][j].end()) {
        a1 -= A[i+2][j];
        D[i+2][j] = i;
      } else {
        a1 += A[i+2][j];
        D[i+2][j] = i+2;
      }
    }
  }
  printyesno(flag);
  if (!flag)
    return 0;
  int d = 1;
  rep(i,N) {
    cout << (((d+1)%4 == D[i%4][i/4]) ? 'R' : 'L');
    d = D[i%4][i/4];
  }
  cout << endl;
  return 0;
}