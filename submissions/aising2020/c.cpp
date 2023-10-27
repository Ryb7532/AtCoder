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
  auto f = [](int x, int y, int z) {
    return x*x+y*y+z*z+x*y+y*z+z*x;
  };
  rep(n,1,N+1) {
    int res = 0;
    for (int x=1; f(x,x,x)<=n; x++) {
      for (int y=x; f(x,y,y)<=n; y++) {
        int z = y;
        while (f(x,y,z)<n)
          z++;
        if (f(x,y,z) != n)
          continue;
        int cnd = (x == y) + (y == z) + (z == x);
        if (cnd == 3)
          res += 1;
        else if (cnd == 1)
          res += 3;
        else
          res += 6;
      }
    }
    print(res);
  }
  return 0;
}