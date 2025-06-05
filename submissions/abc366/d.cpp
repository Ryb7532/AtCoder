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

int main() {
  int N, Q;
  scan(N);
  vector<vector<vector<ll>>> A(N+1, vector<vector<ll>>(N+1, vector<ll>(N+1, 0)));
  ll a;
  rep(x, N) {
    rep(y, N) {
      rep(z, N) {
        scan(a);
        A[x+1][y+1][z+1] = a + A[x+1][y+1][z];
      }
      rep(z, N+1) {
        A[x+1][y+1][z] += A[x+1][y][z];
      }
    }
    rep(y, N+1) {
      rep(z, N+1) {
        A[x+1][y][z] += A[x][y][z];
      }
    }
  }
  scan(Q);
  rep(_, Q) {
    int Lx, Rx, Ly, Ry, Lz, Rz;
    scan(Lx, Rx, Ly, Ry, Lz, Rz);
    Lx--, Ly--, Lz--;
    ll res = A[Rx][Ry][Rz];
    res -= A[Lx][Ry][Rz] + A[Rx][Ly][Rz] + A[Rx][Ry][Lz];
    res += A[Lx][Ly][Rz] + A[Lx][Ry][Lz] + A[Rx][Ly][Lz];
    res -= A[Lx][Ly][Lz];
    print(res);
  }
  return 0;
}