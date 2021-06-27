#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"

struct Point {
  ld x; ld y;
  Point(ld a=0,ld b=0): x(a), y(b) {}
  Point &operator+=(const Point &p) { x+=p.x; y+=p.y; return *this; }
  Point &operator+=(const ll c) { x+=c; y+=c; return *this; }
  Point &operator-=(const Point &p) { x-=p.x; y-=p.y; return *this; }
  Point &operator-=(const ll c) { x-=c; y-=c; return *this; }
  Point &operator*=(const Point &p) { x*=p.x; y*=p.y; return *this; }
  Point &operator*=(const ll &c) { x*=c; y*=c; return *this; }
  Point operator-() const{ return Point(-x,-y); }
  Point operator+(const Point &p) const { return Point(*this)+=p; }
  Point operator-(const Point &p) const { return Point(*this)-=p; }
  Point operator*(const Point &p) const { return Point(*this)*=p; }
  friend Point operator*(const Point &p, const ll c) { return Point(p) *= c; }
  friend Point operator*(const ll c, const Point &p) { return Point(p) *= c; }
  bool operator==(const Point &p) const { return x==p.x && y==p.y; }
  bool operator!=(const Point &p) const { return x!=p.x || y!=p.y; }
  Point swap() const { return Point(y,x); }
  friend ostream &operator<<(ostream &os, const Point &p) { return os << p.x << "," << p.y; }
  friend istream &operator>>(istream &is, Point &p) {
    ll a,b;
    is >> a >> b;
    p = Point(a,b);
    return (is);
  }
  ld distance(const Point &p) {
    ld x_2, y_2;
    x_2 = (x-p.x)*(x-p.x);
    y_2 = (y-p.y)*(y-p.y);
    return sqrtl(x_2+y_2);
  }
};

const ld eps = 1e-6;

int main() {
  int N;
  cin >> N;
  vec<Point> A(N),B(N);
  Point ga,gb;
  rep(i,N) {
    cin >> A[i];
    ga += A[i];
  }
  rep(j,N) {
    cin >> B[j];
    gb += B[j];
  }
  ga.x /= N; ga.y /= N;
  gb.x /= N; gb.y /= N;
  rep(i,N) {
    A[i] -= ga;
  }
  rep(j,N) {
    B[j] -= gb;
  }
  if (N == 1) {
    print(Yes);
    return 0;
  }
  if (A[0] == Point(0,0))
    swap(A[1],A[0]);
  for (int i=0; i<N; i++) {
    bool can = true;
    ld ang = atan2(B[i].y,B[i].x)-atan2(A[0].y,A[0].x);
    for (int k=0; k<N; k++) {
      bool check = false;
      ld x,y;
      x = B[k].x*cos(ang) + B[k].y*sin(ang);
      y = - B[k].x*sin(ang) + B[k].y*cos(ang);
      for (int j=0; j<N; j++) {
        if (abs(x-A[j].x)<=eps && abs(y-A[j].y)<=eps)
          check = true;
      }
      can = can & check;
    }
    if (can) {
      print(Yes);
      return 0;
    }
  }
  print(No);
  return 0;
}
