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
#define rrep1(n) rrep2(_,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define out1(a) cout << (a) << endl
#define out2(a,b) cout << (a) << " " << (b) << endl
#define out3(a,b,c) cout << (a) << " " << (b) << " " << (c) << endl
#define print(...) GET_MACRO(__VA_ARGS__,out3,out2,out1)(__VA_ARGS__)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

int main() {
  int N;
  cin >> N;
  vector<string> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  random_device seed;
  mt19937_64 engine(seed());
  vector<ll> S;
  rep(50) {
    S.push_back(1e9+engine()%(ll)1e9);
  }
  vector<vector<ll>> mod(N, vector<ll>(50, 0));
  rep(j,50) {
    rep(i,N) {
      fore(d, A[i]) {
        mod[i][j] *= 10;
        mod[i][j] += d-'0';
        mod[i][j] %= S[j];
      }
    }
  }
  sort(all(mod));
  ll res = 0;
  rep(i,N) {
    rep(j,N) {
      vector<ll> m;
      rep(k,50) {
        m.push_back((mod[i][k] * mod[j][k])%S[k]);
      }
      int ll = -1, lr = N;
      int rl = -1, rr = N;
      while (lr-ll > 1) {
        int lm = (ll+lr)/2;
        if (mod[lm] >= m) lr = lm;
        else ll = lm;
      }
      while (rr-rl > 1) {
        int rm = (rl+rr)/2;
        if (mod[rm] > m) rr = rm;
        else rl = rm;
      }
      res += rr-lr;
    }
  }
  print(res);
  return 0;
}