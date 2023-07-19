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

int H, W;
vector<int> dh = {1,1,0,-1,-1,-1,0,1}, dw = {0,1,1,1,0,-1,-1,-1};

bool isRange(int h, int w) {
  return h>=0 && h<H && w>=0 && w<W;
}

int main() {
  cin >> H >> W;
  vector<string> S(H);
  rep(i,H) {
    cin >> S[i];
  }
  string snuke = "snuke";
  rep(i,H) {
    rep(j,W) {
      rep(k,8) {
        bool flag = true;
        rep(l,5) {
          int x = i+l*dh[k], y = j+l*dw[k];
          if (isRange(x, y) && S[x][y] == snuke[l])
            continue;
          flag = false;
          break;
        }
        if (flag) {
          rep(l,5) {
            print(i+l*dh[k]+1 << " " << j+l*dw[k]+1);
          }
        }
      }
    }
  }
  return 0;
}
