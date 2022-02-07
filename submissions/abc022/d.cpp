#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


template< typename T >
struct Point {
  T x; T y;
  Point(T a=0,T b=0): x(a), y(b) {}
  Point &operator+=(const Point &p) { x+=p.x; y+=p.y; return *this; }
  Point &operator+=(const T c) { x+=c; y+=c; return *this; }
  Point &operator-=(const Point &p) { x-=p.x; y-=p.y; return *this; }
  Point &operator-=(const T c) { x-=c; y-=c; return *this; }
  Point &operator*=(const Point &p) { x*=p.x; y*=p.y; return *this; }
  Point &operator*=(const T &c) { x*=c; y*=c; return *this; }
  Point operator-() const{ return Point(-x,-y); }
  Point operator+(const Point &p) const { return Point(*this)+=p; }
  Point operator-(const Point &p) const { return Point(*this)-=p; }
  Point operator*(const Point &p) const { return Point(*this)*=p; }
  friend Point operator*(const Point &p, const T c) { return Point(p) *= c; }
  friend Point operator*(const T c, const Point &p) { return Point(p) *= c; }
  bool operator==(const Point &p) const { return x==p.x && y==p.y; }
  bool operator!=(const Point &p) const { return x!=p.x || y!=p.y; }
  Point swap() const { return Point(y,x); }
  friend ostream &operator<<(ostream &os, const Point &p) { return os << p.x << "," << p.y; }
  friend istream &operator>>(istream &is, Point &p) {
    T a,b;
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


int main() {
  int N;
  cin >> N;
  vector<Point<ld>> A(N), B(N);
  Point<ld> Ga, Gb;
  vector<ld> disA(N), disB(N);
  rep(i,N) {
    cin >> A[i];
    Ga += A[i];
  }
  rep(i,N) {
    cin >> B[i];
    Gb += B[i];
  }
  Ga.x /= N; Ga.y /= N;
  Gb.x /= N; Gb.y /= N;
  rep(i,N) {
    disA[i] = Ga.distance(A[i]);
  }
  rep(i,N) {
    disB[i] = Gb.distance(B[i]);
  }
  sort(rall(disA));
  sort(rall(disB));
  ld res = disB[0]/disA[0];
  print(fix(9)<<res);
  return 0;
}
