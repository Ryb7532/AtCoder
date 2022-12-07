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
  int N;
  cin >> N;
  vec<string> x(N);
  rep(i,N) cin >> x[i];
  int ans = 0;
  rep(i,9) {
    char p = '.';
    rep(j,N) {
      if (x[j][i] == 'x')
        ans++;
      if (x[j][i] == 'o' && p != 'o')
        ans++;
      p = x[j][i];
    }
  }
  print(ans);
  return 0;
}
