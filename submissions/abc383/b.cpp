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
  int H,W,D;
  scan(H,W,D);
  vector<string> S(H);
  int res = 0;
  rep(i,H) scan(S[i]);
  vector<int> X, Y;
  rep(i,H) {
    rep(j,W) {
      if (S[i][j] != '.') continue;
      X.push_back(i);
      Y.push_back(j);
    }
  }
  int N = X.size();
  auto distance = [&](int a, int b) {
    return abs(X[a]-X[b]) + abs(Y[a]-Y[b]);
  };
  rep(i,N) {
    rep(j,N) {
      if (i == j) continue;
      int tmp = 0;
      rep(k,N) {
        if (distance(i,k) <= D || distance(j,k) <= D) tmp++;
      }
      chmax(res, tmp);
    }
  }
  print(res);
  return 0;
}