#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


const ll mod = 998244353;
struct mint {
  ll x;
  mint(ll x=0) : x((x%mod+mod)%mod) {}
  mint &operator+=(const mint &p) { if((x += p.x) >= mod) x -= mod; return *this; }
  mint &operator-=(const mint &p) { if((x += mod - p.x) >= mod) x -= mod; return *this; }
  mint &operator*=(const mint &p) { x = x * p.x % mod; return *this; }
  mint &operator/=(const mint &p) { *this *= p.inverse(); return *this; }
  mint operator-() const { return mint(-x); }
  mint operator+(const mint &p) const { return mint(*this) += p; }
  friend mint operator+(const int &c,const mint &p) { return mint(c) += p; }
  mint operator-(const mint &p) const { return mint(*this) -= p; }
  friend mint operator-(const int &c,const mint &p) { return mint(c) -= p; }
  mint operator*(const mint &p) const { return mint(*this) *= p; }
  friend mint operator*(const int &c,const mint &p) { return mint(c) *= p; }
  mint operator/(const mint &p) const { return mint(*this) /= p; }
  friend mint operator/(const int &c,const mint &p) { return mint(c) /= p; }
  bool operator==(const mint &p) const { return x == p.x; }
  friend bool operator==(const int &c,const mint &p) { return mint(c) == p; }
  bool operator!=(const mint &p) const { return x != p.x; }
  friend bool operator!=(const int &c, const mint &p) { return mint(c) != p; }
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
  friend ostream &operator<<(ostream &os,const mint &p) { return os << p.x; }
  friend istream &operator>>(istream &is,mint &a) {
    ll t;
    is >> t;
    a = mint(t);
    return (is);
  }
};


int N;
vec<vec<pair<int,int>>> Edge(1000);
vec<ll> cnt(1000,0);
vec<ll> P(1000,0);

void dfs(int n, int p, int g) {
  if (n == g) {
    rep(i,N-1) {
      P[i] += cnt[i];
    }
    return ;
  }
  for (auto e: Edge[n]) {
    if (e.first == p)
      continue;
    cnt[e.second]++;
    dfs(e.first, n, g);
    cnt[e.second]--;
  }
  return ;
}

int main() {
  int M,K;
  cin >> N >> M >> K;
  K = abs(K);
  vec<int> A(M);
  rep(i,M) {
    cin >> A[i];
    A[i]--;
  }
  rep(i,N-1) {
    int U,V;
    cin >> U >> V;
    U--; V--;
    Edge[U].push_back({V,i});
    Edge[V].push_back({U,i});
  }
  rep(i,M-1) {
    dfs(A[i], -1, A[i+1]);
  }
  ll sum = 0;
  rep(i,N-1) {
    sum += P[i];
  }
  if (sum < K || (sum-K)%2) {
    print(0);
    return 0;
  }
  sum = (sum-K)/2;
  vec<vec<mint>> dp(N, vec<mint>(sum+1));
  dp[0][0] = 1;
  rep(i,N-1) {
    rep(j,sum+1) {
      dp[i+1][j] += dp[i][j];
      if (j+P[i] > sum)
        continue;
      dp[i+1][j+P[i]] += dp[i][j];
    }
  }
  print(dp[N-1][sum]);
  return 0;
}
