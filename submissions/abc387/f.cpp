#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep1(n) rep2(_,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define printyn(f) cout << ((f) ? "Yes" : "No") << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}
void print() {cout << endl;}
template<typename Arg, typename... Args> void print(const Arg a, const Args... b) {
  cout << a;
  (cout << ... << (cout << ' ', b)) << endl;
}
template<class... T> void scan(T&... a) {(cin >> ... >> a);}

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

int main() {
  int N,M;
  scan(N,M);
  vector<int> A(N);
  vector<vector<int>> O(N);
  rep(i,N) {
    int a;
    scan(a);
    a--;
    A[i] = a;
    O[a].push_back(i);
  }
  vector<int> visited(N,0); // visited[i]==2 => i is on the cycle, visited[i]>=1 => i is on visited connected components
  vector<int> seen_edge(N,-1);
  vector<vector<mint>> dp(N, vector<mint>(M,1));
  mint res = 1;
  rep(i,N) {
    if (visited[i] != 0) continue;
    vector<int> root_cycle, st;
    int v = i, u = A[i];
    visited[v]++;
    while (visited[u] == 0) {
      v = u;
      u = A[v];
      visited[v]++;
    }
    visited[v]++;
    root_cycle.push_back(v);
    while (visited[u] == 1) {
      v = u;
      u = A[v];
      visited[v]++;
      root_cycle.push_back(v);
    }
    int root = root_cycle[0];
    vector<int> root_out;
    fore(r,root_cycle) {
      fore(o, O[r]) if (visited[o] != 2) root_out.push_back(o);
    }
    O[root].assign(all(root_out));
    st.push_back(root);
    while (!st.empty()) {
      u = st.back();
      if (seen_edge[u] >= 0) {
        v = O[u][seen_edge[u]];
        rep(j,M) dp[u][j] *= dp[v][j];
      }
      seen_edge[u]++;
      if (seen_edge[u] == O[u].size()) {
        st.pop_back();
        rep(j,M-1) dp[u][j+1] += dp[u][j];
        continue;
      }
      v = O[u][seen_edge[u]];
      if (visited[v] == 0) visited[v]++;
      if (visited[v] != 2) st.push_back(v);
    }
    res *= dp[root][M-1];
  }
  print(res);
  return 0;
}