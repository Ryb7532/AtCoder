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
  int N,Q;
  string S;
  scan(N,Q,S);
  int res = 0;
  vector<bool> isABC(N-2,false);
  rep(i,N-2) {
    if (S.substr(i,3) == "ABC") {
      res++;
      isABC[i] = true;
    }
  }
  rep(_,Q) {
    int X;
    char C;
    scan(X,C);
    X--;
    rep(i,3) {
      int pos = X - i;
      if (pos < 0 || pos >= N-2) continue;
      if (isABC[pos]) {
        res--;
        isABC[pos] = false;
      }
    }
    S[X] = C;
    rep(i,3) {
      int pos = X - i;
      if (pos < 0 || pos >= N-2) continue;
      if (S.substr(pos,3) == "ABC") {
        res++;
        isABC[pos] = true;
      }
    }
    print(res);
  }
  return 0;
}