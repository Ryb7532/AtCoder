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
  vec<int> res(6,0);
  rep(i,N) {
    ld M,m;
    cin >> M >> m;
    if (M>=35.0)
      res[0]++;
    else if (M>=30.0)
      res[1]++;
    else if (M>=25.0)
      res[2]++;
    else if (M<0.0)
      res[5]++;
    if (m>=25.0)
      res[3]++;
    if (m<0.0 && M>=0.0)
      res[4]++;
  }
  print(res[0] << ' ' << res[1] << ' ' << res[2] << ' ' << res[3] << ' ' << res[4] << ' ' << res[5]);
  return 0;
}
