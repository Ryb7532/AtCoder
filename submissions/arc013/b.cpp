#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << a << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int main() {
  int C;
  cin >> C;
  vec<int> res(3,0);
  rep(i,C) {
    vec<int> s(3);
    cin >> s[0] >> s[1] >> s[2];
    sort(all(s));
    rep(i,3) {
      res[i] = max(res[i],s[i]);
    }
  }
  print(res[0]*res[1]*res[2]);
  return 0;
}
