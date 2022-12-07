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
typedef struct {int x; int y;} point;
double dis(point a, point b) {
  point s = {a.x-b.x, a.y-b.y};
  return sqrt(s.x*s.x+s.y*s.y);
}

int main() {
  point p1, p2, p3, p4, p5;
  int r;
  cin >> p1.x >> p1.y >> r >> p2.x >> p2.y >> p3.x >> p3.y;
  p4 = {p2.x, p3.y}; p5 = {p3.x, p2.y};
  bool red, blue;
  if (p1.x+r<=p3.x && p1.x-r>=p2.x && p1.y+r<=p3.y && p1.y+r>=p2.y)
    red = false;
  else
    red = true;
  if (dis(p1,p2)<=r && dis(p1,p3)<=r && dis(p1,p4)<=r && dis(p1,p5)<=r)
    blue = false;
  else
    blue = true;
  print(red?"YES":"NO");
  print(blue?"YES":"NO");
  return 0;
}
