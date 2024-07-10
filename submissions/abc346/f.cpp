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
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}

int main() {
  ll N;
  string S,T;
  cin >> N >> S >> T;
  int s = S.size();
  int t = T.size();
  vector<vector<int>> pos(26);
  rep(i,s) {
    pos[S[i]-'a'].push_back(i);
  }
  ll l = 0, r = 1e18;
  while (r-l > 1) {
    ll m = (r+l)/2;
    ll n = 0;
    int p = 0;
    rep(i,t) {
      int c = T[i] - 'a';
      if (pos[c].size() == 0) {
        n = N;
        break;
      }
      ll j = lower_bound(all(pos[c]), p) - pos[c].begin();
      int sz = pos[c].size();
      j += m-1;
      n += j / sz;
      p = pos[c][j%sz]+1;
      if (n >= N)
        break;
    }
    if (n < N)
      l = m;
    else
      r = m;
  }
  print(l);
  return 0;
}