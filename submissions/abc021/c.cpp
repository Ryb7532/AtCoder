#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()

const ll mod = 1e9+7;
struct mint {
  ll x;
  mint(ll x=0) : x((x%mod+mod)%mod) {}
  mint &operator+=(const mint &p) { if((x += p.x) >= mod) x -= mod; return *this; }
  mint &operator-=(const mint &p) { if((x += mod - p.x) >= mod) x -= mod; return *this; }
  mint &operator*=(const mint &p) { x = x * p.x % mod; return *this; }
  mint &operator/=(const mint &p) { *this *= p.inverse(); return *this; }
  mint operator-() const { return mint(-x); }
  mint operator+(const mint &p) const { return mint(*this) += p; }
  mint operator-(const mint &p) const { return mint(*this) -= p; }
  mint operator*(const mint &p) const { return mint(*this) *= p; }
  mint operator/(const mint &p) const { return mint(*this) /= p; }
  bool operator==(const mint &p) const { return x == p.x; }
  bool operator!=(const mint &p) const { return x != p.x; }
  mint inverse() const {
    ll a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return mint(u);
  }
  mint pow(ll n) const {
    mint ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os, const mint &p) { return os << p.x; }
  friend istream &operator>>(istream &is, mint &a) {
    ll t;
    is >> t;
    a = mint(t);
    return (is);
  }
};

//warshall_floyd
const int MAX_V = 100;
const int INF = 1e9;
int V;
ll d[MAX_V][MAX_V];
vector<int> edge[MAX_V];
mint cnt[MAX_V];

void init() {
  for (int i=0; i<V; i++)
    for (int j=0; j<V; j++)
      if (i != j)
        d[i][j] = INF;
}

void warshall_floyd() {
  for (int k=0; k<V; k++) {
    for (int i=0; i<V; i++) {
      for (int j=0; j<V; j++) {
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
      }
    }
  }
}

void dfs(int s, int g) {
  if (s == g) {
    cnt[s] = 1;
    return;
  }
  mint res = 0;
  for (auto &e: edge[s]) {
    if (d[e][g] < d[s][g]) {
      if (cnt[e]==0)
        dfs(e, g);
      res += cnt[e];
    }
  }
  cnt[s] = res;
  return;
}

int main() {
  cin >> V;
  int a, b, M, x, y;
  cin >> a >> b >> M;
  a--; b--;
  init();
  rep(i, M) {
    cin >> x >> y;
    x--; y--;
    d[x][y] = d[y][x] = 1;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  warshall_floyd();
  dfs(a, b);
  print(cnt[a]);
  return 0;
}
