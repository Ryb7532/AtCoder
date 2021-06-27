#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


struct Point {
  ll x; ll y;
  Point(ll a=0,ll b=0) { x=a; y=b; }
  Point &operator+=(const Point &p) { x+=p.x; y+=p.y; return *this; }
  Point &operator+=(const ll c) { x+=c; y+=c; return *this; }
  Point &operator-=(const Point &p) { x-=p.x; y-=p.y; return *this; }
  Point &operator-=(const ll c) { x-=c; y-=c; return *this; }
  Point &operator*=(const Point &p) { x*=p.x; y*=p.y; return *this; }
  Point &operator*=(const ll &c) { x*=c; y*=c; return *this; }
  Point operator-() const{ return Point(-x,-y); }
  Point operator+(const Point &p) const { return Point(*this)+=p; }
  friend Point operator+(const Point &p, const ll c) { return Point(p)+=c; }
  friend Point operator+(const ll c, const Point &p) { return Point(p)+=c; }
  Point operator-(const Point &p) const { return Point(*this)-=p; }
  friend Point operator-(const Point &p, const ll c) { return Point(p)-=c; }
  friend Point operator-(const ll c, const Point &p) { return Point(p)-=c; }
  Point operator*(const Point &p) const { return Point(*this)*=p; }
  friend Point operator*(const Point &p, const ll c) { return Point(p)*=c; }
  friend Point operator*(const ll c, const Point &p) { return Point(p)*=c; }
  bool operator==(const Point &p) const { return x==p.x && y==p.y; }
  bool operator!=(const Point &p) const { return x!=p.x || y!=p.y; }
  Point swap() const { return Point(y,x); }
  friend ostream &operator<<(ostream &os, const Point &p) { return os << p.x << " " << p.y; }
  friend istream &operator>>(istream &is, Point &p) {
    ll a,b;
    is >> a >> b;
    p = Point(a,b);
    return (is);
  }
};


int main() {
  int N;
  cin >> N;
  vector<Point> p(N);
  rep(i,N) {
    cin >> p[i];
  }
  int ans = 0;
  rep(i,N) {
    reps(j,i+1,N) {
      reps(k,j+1,N) {
        Point a,b;
        a = p[j]-p[i];
        b = p[k]-p[i];
        ll s = a.x*b.y-a.y*b.x;
        if (s != 0 && s%2 == 0)
          ans++;
      }
    }
  }
  print(ans);
  return 0;
}
