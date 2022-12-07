#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  string S;
  cin >> S;
  int n = S.size();
  vec<int> N(n);
  rep(i,n) {
    N[i] = S[i]-'0';
  }
  ll res = 0;
  for (int i=1; i<(1<<n)-1; i++) {
    vec<int> A,B;
    rep(j,n) {
      if (i&(1<<j)) {
        A.push_back(N[j]);
      } else {
        B.push_back(N[j]);
      }
    }
    sort(rall(A));
    sort(rall(B));
    ll a=0, b=0;
    for (int a_: A) {
      a *= 10;
      a += a_;
    }
    for (int b_: B) {
      b *= 10;
      b += b_;
    }
    res = max(res, a*b);
  }
  print(res);
  return 0;
}
