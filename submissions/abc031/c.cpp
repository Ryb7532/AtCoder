#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; (i)<(n); (i)++)
#define reps(i,s,n) for (int i=(s); (i)<(n); (i)++)
#define rep1(i,n) for (int i=1; (i)<=(n); (i)++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end();
const int INF = 1e5;

int main() {
  int N;
  cin >> N;
  int a[N], ans = -INF;
  rep(i, N) {
    cin >> a[i];
  }
  rep(i, N) {
    int pa = -INF, pt = -INF;
    rep(j, N) {
      if (i == j)
        continue;
      int s = min(i,j), n = abs(i-j)+1;
      int tmpa = 0, tmpt = 0;
      rep(k, n) {
        if (k%2)
          tmpa += a[s+k];
        else
          tmpt += a[s+k];
      }
      if (tmpa > pa) {
        pa = tmpa;
        pt = tmpt;
      }
    }
    ans = max(ans, pt);
  }
  print(ans);
  return 0;
}
