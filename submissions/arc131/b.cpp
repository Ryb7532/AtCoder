#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


vector<int> dh = {1,0,-1,0}, dw = {0,1,0,-1};

int main() {
  int H,W;
  cin >> H >> W;
  vector<string> C(H);
  rep(i,H) {
    cin >> C[i];
  }
  rep(i,H) {
    rep(j,W) {
      if (C[i][j] != '.')
        continue;
      vector<bool> used(5,false);
      rep(k,4) {
        if (i+dh[k]<0 || i+dh[k]==H || j+dw[k]<0 || j+dw[k]==W)
          continue;
        char c = C[i+dh[k]][j+dw[k]];
        if (c == '.')
          continue;
        used[c-'1'] = true;
      }
      rep(k,5) {
        if (!used[k]) {
          C[i][j] = k+'1';
          break;
        }
      }
    }
    print(C[i]);
  }
  return 0;
}
