#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()
typedef struct {
  double x;
  double y;
} Point;


double dis(Point a, Point b) {
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main() {
  Point a, b;
  cin >> a.x >> a.y >> b.x >> b.y;
  int T, V, n;
  cin >> T >> V >> n;
  Point p;
  bool ans = false;
  rep(i, n) {
    cin >> p.x >> p.y;
    if (T*V>=dis(a, p)+dis(p, b))
      ans = true;
  }
  print((ans)?"YES":"NO");
  return 0;
}
