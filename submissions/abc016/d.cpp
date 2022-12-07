#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()

typedef struct {
  int x;
  int y;
} Point;

int f(Point p1, Point p2, Point p3) {
  return ((p2.x-p1.x)*(p3.y-p1.y) - (p2.y-p1.y)*(p3.x-p1.x) < 0) ? -1 : 1;
}

bool intersect(Point p1, Point p2, Point p3, Point p4) {
  int t1 = f(p1, p2, p3), t2 = f(p1, p2, p4), t3 = f(p3, p4, p1), t4 = f(p3, p4, p2);
  return t1*t2<=0 && t3*t4<=0;
}

int main() {
  int N;
  Point A, B;
  cin >> A.x >> A.y >> B.x >> B.y >> N;
  Point p[N];
  int cnt = 0;
  rep(i, N) {
    cin >> p[i].x >> p[i].y;
  }
  rep(i, N-1) {
    if (intersect(p[i], p[i+1], A, B))
      cnt++;
  }
  if (intersect(p[N-1], p[0], A, B))
    cnt++;
  cnt /= 2;
  cnt++;
  print(cnt);
  return 0;
}
