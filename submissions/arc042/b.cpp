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
typedef struct {ld x; ld y;} Point;

ld dis(Point p0, Point p1, Point p2) {
  ld a = p2.x-p1.x, b = p2.y-p1.y;
  ld f = a*(p1.y-p0.y)-b*(p1.x-p0.x);
  ld r = a*a+b*b;
  return sqrtl(f*f/r);
}

int main() {
  Point t;
  int N;
  cin >> t.x >> t.y >> N;
  Point v[N];
  rep(i,N) {
    cin >> v[i].x >> v[i].y;
  }
  ld ans = dis(t,v[0],v[N-1]);
  rep1(i,N-1) {
    ans = min(ans,dis(t,v[i],v[i-1]));
  }
  printf("%.8Lf\n",ans);
  return 0;
}
