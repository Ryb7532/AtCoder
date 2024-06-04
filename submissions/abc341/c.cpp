#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep1(n) rep2(_,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define out1(a) cout << (a) << endl
#define out2(a,b) cout << (a) << " " << (b) << endl
#define out3(a,b,c) cout << (a) << " " << (b) << " " << (c) << endl
#define print(...) GET_MACRO(__VA_ARGS__,out3,out2,out1)(__VA_ARGS__)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

int main() {
  int H,W,N;
  string T;
  cin >> H >> W >> N >> T;
  vector<string> S(H);
  rep(i,H) {
    cin >> S[i];
  }
  string d = "LRUD";
  int dx[] = {0,0,-1,1}, dy[] = {-1,1,0,0};
  int res = 0;
  rep(i,H) {
    rep(j,W) {
      int x = i, y = j;
      rep(k,N) {
        if (S[x][y] == '#')
          break;
        rep(l,4) {
          if (T[k] == d[l]) {
            x += dx[l];
            y += dy[l];
          }
        }
      }
      if (S[x][y] == '#')
        continue;
      res++;
    }
  }
  print(res);
  return 0;
}