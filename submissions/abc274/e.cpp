#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


// Coordinate on a two-dimensional plane
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
  int N,M;
  cin >> N >> M;
  vector<Point<ll>> P(N+M);
  rep(i,N+M) {
    cin >> P[i];
  }
  Point<ll> O;
  const ld maxC = 1e15;
  vector<vector<ld>> dp(N+M, vector<ld>(1<<(N+M), maxC));
  rep(i,N+M) {
    dp[i][1<<i] = P[i].distance(O);
  }
  ld res = maxC;
  for (int i=1; i<(1<<(N+M)); i++) {
    ld speed = 1;
    for (int j=N; j<N+M; j++) {
      if (i & (1<<j))
        speed *= 2;
    }
    rep(j,N+M) {
      if ((i & (1<<j)) == 0)
        continue;
      rep(k,N+M) {
        if (i & (1<<k))
          continue;
        dp[k][i+(1<<k)] = min(dp[k][i+(1<<k)], dp[j][i] + P[j].distance(P[k])/speed);
      }
      if ((i & ((1<<N)-1)) == (1<<N)-1) {
        res = min(res, dp[j][i] + P[j].distance(O)/speed);
      }
    }
  }
  print(fix(10) << res);
  return 0;
}
