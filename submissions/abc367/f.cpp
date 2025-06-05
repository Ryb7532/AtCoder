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


ll mod = (1LL << 60) - 1;

int main() {
  int N,Q;
  scan(N,Q);
  vector<int> A(N), B(N);
  fore(a,A) {
    scan(a);
  }
  fore(b,B) {
    scan(b);
  }
  random_device seed_gen;
  mt19937 engine(seed_gen());
  uniform_int_distribution<ll> dist(0, mod);
  map<int,ll> hash0, hash1;
  rep(i,N) {
    hash0[i+1] = dist(engine);
    hash1[i+1] = dist(engine);
  }
  vector<pair<ll,ll>> C(N+1), D(N+1);
  rep(i,N) {
    C[i+1].first = (C[i].first + hash0[A[i]]) % mod;
    C[i+1].second = (C[i].second + hash1[A[i]]) % mod;
    D[i+1].first = (D[i].first + hash0[B[i]]) % mod;
    D[i+1].second = (D[i].second + hash1[B[i]]) % mod;
  }
  rep(_,Q) {
    int l, r, L, R;
    scan(l, r, L, R);
    l--; L--;
    ll ha0, ha1, hb0, hb1;
    ha0 = (C[r].first - C[l].first + mod) % mod;
    ha1 = (C[r].second - C[l].second + mod) % mod;
    hb0 = (D[R].first - D[L].first + mod) % mod;
    hb1 = (D[R].second - D[L].second + mod) % mod;
    printyn(ha0 == hb0 && ha1 == hb1);
  }
  return 0;
}