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
  int H,W,Q;
  scan(H,W,Q);
  vector<set<int>> X(H+1),Y(W+1);
  rep(i,H) {
    rep(j,W) {
      X[i].insert(j);
      Y[j].insert(i);
    }
  }
  rep(_,Q) {
    int R,C;
    scan(R,C);
    R--; C--;
    auto xit = X[R].lower_bound(C);
    auto yit = Y[C].lower_bound(R);
    int l = W, r = W, u = H, d = H;
    if (xit != X[R].end()) r = *xit;
    if (xit != X[R].begin()) l = *(--xit);
    if (yit != Y[C].end()) u = *yit;
    if (yit != Y[C].begin()) d = *(--yit);
    if (r == C) {
      l = C;
      d = R;
    }
    X[R].erase(l); Y[l].erase(R);
    X[R].erase(r); Y[r].erase(R);
    X[u].erase(C); Y[C].erase(u);
    X[d].erase(C); Y[C].erase(d);
  }
  int res = 0;
  rep(i,H) {
    res += X[i].size();
  }
  print(res);
  return 0;
}