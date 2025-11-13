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
  int N;
  scan(N);
  vector<string> A(N);
  rep(i,N) scan(A[i]);
  vector<string> T(N);
  rep(i, N) T[i].resize(N);
  auto rev = [&](int x, int y, int r) {
    r++;
    r %= 4;
    if (r == 0) return make_pair(x, y);
    if (r == 1) return make_pair(y, N-1 - x);
    if (r == 2) return make_pair(N-1 - x, N-1 - y);
    return make_pair(N-1 - y, x);
  };
  rep(i, N/2) {
    rep(j, N) {
      if (j < i || j >= N-1 - i)
        continue;
      rep(k, 4) {
        auto [x,y] = rev(i, j, k);
        auto [u,v] = rev(x, y, i);
        T[u][v] = A[x][y];
      }
    }
  }
  rep(i,N) print(T[i]);
  return 0;
}