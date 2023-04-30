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
  int H,W;
  cin >> H >> W;
  vector<string> C(H);
  rep(i,H) {
    cin >> C[i];
  }
  int N = min(H,W);
  vector<int> res(N+1, 0);
  rep(i,H) {
    rep(j,W) {
      int size = 0;
      if (C[i][j] == '.')
        continue;
      while (true) {
        if (i-size >= 0 && i+size < H && j-size>=0 && j+size<W && C[i+size][j+size] == '#' && C[i+size][j-size] == '#' && C[i-size][j+size] == '#' && C[i-size][j-size] == '#')
          size++;
        else
          break;
      }
      res[size-1]++;
    }
  }
  rep(i,N) {
    cout << res[i+1] << " ";
  }
  cout << endl;
  return 0;
}
