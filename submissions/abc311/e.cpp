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

int main() {
  int H,W,N;
  cin >> H >> W >> N;
  vector<vector<ll>> cnt(H+1, vector<ll>(W+1, 0));
  rep(i,N) {
    int a,b;
    cin >> a >> b;
    cnt[a][b]++;
  }
  rep(i,H) {
    rep(j,W)
      cnt[i+1][j+1] += cnt[i+1][j];
    rep(j,W)
      cnt[i+1][j+1] += cnt[i][j+1];
  }
  ll res = 0;
  rep(i,H) {
    rep(j,W) {
      int l = 0, u = min(H-i, W-j)+1;
      while (u-l > 1) {
        int m = (u+l)/2;
        ll c = cnt[i+m][j+m] - cnt[i+m][j] - cnt[i][j+m] + cnt[i][j];
        if (c == 0)
          l = m;
        else 
          u = m;
      }
      res += l;
    }
  }
  print(res);
  return 0;
}
