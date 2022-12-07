#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()

typedef struct{
  int x;
  int y;
} Point;

double triangle(Point a, Point b, Point c) {
  return (double)abs((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y))/2.0;
}

int main() {
  Point A, B, C;
  cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
  printf("%.2lf\n", triangle(A, B, C));
  return 0;
}
