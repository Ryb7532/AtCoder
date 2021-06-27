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
typedef struct{ld x; ld y;} point;
typedef struct{point center; ld size;} square;

bool inner(square sq, point p) {
  ld x = sq.center.x, y = sq.center.y, s = sq.size;
  return (p.x>=x-s && p.x<=x+s && p.y>=y-s && p.y<=y+s);
}

bool overlap(square sq1, square sq2) {
  ld x1 = sq1.center.x, y1 = sq1.center.y, s1 = sq1.size, x2 = sq2.center.x, y2 = sq2.center.y, s2 = sq2.size;
  return
  inner(sq1, {x2+s2,y2+s2}) || inner(sq1, {x2+s2,y2-s2}) || inner(sq1, {x2-s2,y2+s2}) || inner(sq1, {x2-s2,y2-s2}) || inner(sq2, {x1+s1,y1+s1}) || inner(sq2, {x1+s1,y1-s1}) || inner(sq2, {x1-s1,y1+s1}) || inner(sq2, {x1-s1,y1-s1});
}

int main() {
  int N;
  cin >> N;
  ld x[N], y[N], c[N];
  rep(i,N) {
    cin >> x[i] >> y[i] >> c[i];
  }
  ld b = 0.0, t = 100000000.0;
  while (t-b>0.00000001) {
    ld m = (t+b)/2;
    bool check = true;
    rep(i,N) {
      square s1 = {{x[i],y[i]},m/c[i]};
      rep(j,N) {
        square s2 = {{x[j],y[j]},m/c[j]};
        if (!overlap(s1,s2)) {
          check = false;
          break;
        }
      }
      if (!check)
        break;
    }
    if (check)
      t = m;
    else
      b = m;
  }
  printf("%.8Lf\n",t);
  return 0;
}
