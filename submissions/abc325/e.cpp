#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

int main() {
  int N;
  ll A,B,C;
  cin >> N >> A >> B >> C;
  const ll INF = 1e18;
  vector<vector<ll>> D(N, vector<ll>(N, INF));
  rep(i,N) {
    rep(j,N) {
      cin >> D[i][j];
    }
  }
  vector<ll> from(N), to(N);
  rep(i,N) {
    from[i] = D[0][i]*A;
    to[i] = D[N-1][i]*B+C;
  }
  to[N-1] = 0;
  vector<bool> ff(N, false), ft(N, false);
  ff[0] = true;
  ft[N-1] = true;
  rep(_,N-1) {
    ll mf = INF, mt = INF;
    int amf, amt;
    rep(i,N) {
      if (!ff[i] && mf > from[i]) {
        mf = from[i];
        amf = i;
      }
      if (!ft[i] && mt > to[i]) {
        mt = to[i];
        amt = i;
      }
    }
    ff[amf] = true;
    ft[amt] = true;
    rep(i,N) {
      from[i] = min(from[i], from[amf]+D[amf][i]*A);
      to[i] = min(to[i], to[amt]+D[amt][i]*B+C);
    }
  }
  ll res = INF;
  rep(i,N) {
    res = min(res, from[i]+to[i]);
  }
  print(res);
  return 0;
}