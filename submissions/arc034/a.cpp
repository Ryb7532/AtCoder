#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  int N;
  cin >> N;
  ld ans = 0.0;
  rep(i,N) {
    ld a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    e *= 11.0/90.0;
    ans = max(ans,a+b+c+d+e);
  }
  printf("%.6Lf\n",ans);
  return 0;
}
