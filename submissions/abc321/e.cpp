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
  int T;
  cin >> T;
  rep(_,T) {
    ll N,X,K;
    cin >> N >> X >> K;
    ll res = 0;
    int r = -1;
    while (K >= 0 && X > 0) {
      ll left = X, right = X;
      for (int i=0; i<K; i++) {
        left = 2*left;
        right = 2*right+1;
        if (r == 0) {
          left = right;
          r = -1;
        } else if (r == 1) {
          right = left;
          r = -1;
        }
        if (left > N)
          break;
      }
      res += max(min(right,N)-left+1, 0ll);
      K--;
      r = X % 2;
      X /= 2;
    }
    print(res);
  }
  return 0;
}