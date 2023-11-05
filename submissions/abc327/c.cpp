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
  vector<vector<int>> A(9, vector<int>(9));
  bool flag = true;
  rep(i,9) {
    ll sum = 0;
    ll prod = 1;
    rep(j,9) {
      cin >> A[i][j];
      sum += A[i][j];
      prod *= A[i][j];
    }
    if (!(sum == 45 && prod == 362880))
      flag = false;
  }
  rep(j,9) {
    ll sum = 0;
    ll prod = 1;
    rep(i,9) {
      sum += A[i][j];
      prod *= A[i][j];
    }
    if (!(sum == 45 && prod == 362880))
      flag = false;
  }
  rep(k,9) {
    ll sum = 0;
    ll prod = 1;
    rep(l,9) {
      int i = k/3*3 + l/3;
      int j = k%3*3 + l%3;
      sum += A[i][j];
      prod *= A[i][j];
    }
    if (!(sum == 45 && prod == 362880))
      flag = false;
  }
  printyesno(flag);
  return 0;
}