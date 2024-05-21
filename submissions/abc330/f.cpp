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
#define fore(e,v) for (auto &e: v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

int main() {
  int N;
  ll K;
  cin >> N >> K;
  vector<vector<ll>> P(2, vector<ll>(N));
  rep(i,N) {
    cin >> P[0][i] >> P[1][i];
  }
  sort(all(P[0]));
  sort(all(P[1]));
  vector<vector<ll>> left(2, vector<ll>(N,0)), right(2, vector<ll>(N,0));
  rep(i,1,N) {
    rep(j,2) {
      left[j][i] = left[j][i-1] + i*(P[j][i]-P[j][i-1]);
      right[j][N-1-i] = right[j][N-i] + i*(P[j][N-i]-P[j][N-1-i]);
    }
  }
  ll l = -1, r = 1e9;
  while (r-l > 1) {
    ll m = (r+l)/2;
    vector<ll> dsum(2,1e18);
    rep(i,N) {
      rep(j,2) {
        ll sum = left[j][i];
        int id = lower_bound(all(P[j]),P[j][i]+m)-P[j].begin();
        if (id < N) {
          sum += right[j][id];
          if (P[j][id]-P[j][i] > m) {
            sum += (N-id)*(P[j][id]-P[j][i]-m);
          }
        }
        chmin(dsum[j],sum);
      }
    }
    rep(i,N) {
      rep(j,2) {
        ll sum = right[j][i];
        int id = lower_bound(all(P[j]),P[j][i]-m)-P[j].begin();
        if (id > 0) {
          id--;
        }
        sum += left[j][id];
        if (P[j][i]-P[j][id] > m) {
          sum += (id+1)*(P[j][i]-P[j][id]-m);
        }
        chmin(dsum[j],sum);
      }
    }
    if (dsum[0] + dsum[1] <= K)
      r = m;
    else
      l = m;
  }
  print(r);
  return 0;
}