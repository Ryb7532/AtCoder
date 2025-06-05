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
  int N, D;
  scan(N, D);
  vector<ll> X(N), Y(N);
  rep(i,N) {
    scan(X[i], Y[i]);
  }
  sort(all(X));
  sort(all(Y));
  vector<ll> disX(D+1, 0), disY(D+1, 0);
  ll x = X[0], y = Y[0];
  ll dx = 0, dy = 0;
  rep(i,N) {
    dx += X[i]-x;
    dy += Y[i]-y;
  }
  if (dx <= D) {
    x -= (D-dx) / N;
    dx += (D-dx) / N * N;
  }
  if (dy <= D) {
    y -= (D-dy) / N;
    dy += (D-dy) / N * N;
  }
  while (true) {
    if (dx <= D) disX[dx]++;
    x++;
    int l, r;
    l = lower_bound(all(X), x) - X.begin();
    r = N - l;
    dx += l-r;
    if (l-r > 0 && dx > D) break;
  }
  while (true) {
    if (dy <= D) disY[dy]++;
    y++;
    int l, r;
    l = lower_bound(all(Y), y) - Y.begin();
    r = N - l;
    dy += l-r;
    if (l-r > 0 && dy > D) break;
  }
  rep(i,D) {
    disX[i+1] += disX[i];
  }
  ll res = 0;
  rep(i,D+1) {
    res += disX[i] * disY[D-i];
  }
  print(res);
  return 0;
}