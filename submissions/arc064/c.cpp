#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << a << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

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


//Dijkstra (no minus cost path)
const int MAX_V = 1002;
const ld INF = 1e20;
typedef struct{
  int to;
  ld cost;
} Edge;
typedef pair<ld, int> P; //first:dis second:num

ld d[MAX_V];
vector<Edge> G[MAX_V];

void dijkstra(int s) {
  fill(d, d+MAX_V, INF);
  d[s] = 0;

  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, s));
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first)
      continue;
    for (auto &e: G[v]) {
      if (d[e.to] > d[v]+e.cost) {
        d[e.to] = d[v]+e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}


int N;
vec<pair<Point,int>> circle(1002);


int main() {
  cin >> circle[0].first >> circle[1].first;
  circle[0].second = 0; circle[1].second = 0;
  cin >> N;
  rep(i,N) cin >> circle[2+i].first >> circle[2+i].second;
  rep(i,N+1) {
    reps(j,i+1,N+2) {
      ld t;
      t = circle[i].first.distance(circle[j].first) - circle[i].second - circle[j].second;
      t = max((ld)0.0,t);
      G[i].push_back({j,t});
      G[j].push_back({i,t});
    }
  }
  dijkstra(0);
  cout.precision(20);
  print(d[1]);
  return 0;
}
