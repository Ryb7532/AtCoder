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
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}

int main() {
  int V1, V2, V3;
  cin >> V1 >> V2 >> V3;
  if (V1 + 2*V2 + 3*V3 != 3*7*7*7) {
    print("No");
    return 0;
  }
  vector<vector<int>> c(3, vector<int>(3,0));
  rep(i,8*8*8) {
    rep(j,16*16*16) {
      rep(k,3) {
        c[1][k] = (i>>(k*3))&7;
        c[2][k] = (j>>(k*4))&7;
        if ((j>>(k*4+3))&1)
          c[2][k] *= -1;
      }

      int v3 = 1;
      rep(k,3) {
        int right = 7;
        int left = -7;
        rep(l,3) {
          chmin(right,c[l][k]);
          chmax(left,c[l][k]);
        }
        v3 *= max(0,right+7-left);
      }
      if (v3 != V3)
        continue;

      int v2 = 0;
      rep(k,3) {
        int v = 1;
        rep(l,3) {
          v *= max(0,min(c[k][l], c[(k+1)%3][l])+7-max(c[k][l], c[(k+1)%3][l]));
        }
        v2 += v;
      }
      if (v2 != V2+3*V3)
        continue;

      print("Yes");
      rep(k,9) {
        cout << c[k/3][k%3] << " ";
      }
      cout << endl;
      return 0;
    }
  }
  print("No");
  return 0;
}