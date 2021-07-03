#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;


struct Point {
  ll x; ll y;
  Point(ll a=0,ll b=0): x(a), y(b) {}
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
    ld x_2,y_2;
    x_2 = (x-p.x)*(x-p.x);
    y_2 = (y-p.y)*(y-p.y);
    return sqrtl(x_2+y_2);
  }
};

bool onLine(Point p1, Point p2, Point p3) {
  return (p2.x-p1.x)*(p3.y-p1.y) == (p2.y-p1.y)*(p3.x-p1.x);
}
