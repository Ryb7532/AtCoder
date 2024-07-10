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
  ll H,W,M;
  cin >> H >> W >> M;
  vector<ll> C(2e5+1,0);
  vector<bool> usedH(H, false), usedW(W, false);
  vector<int> T(M), A(M), X(M);
  rep(i,M) {
    cin >> T[i] >> A[i] >> X[i];
    A[i]--;
  }
  rrep(i,M) {
    if (T[i] == 1) {
      if (!usedH[A[i]]) {
        C[X[i]] += W;
        usedH[A[i]] = true;
        H--;
      }
    } else {
      if (!usedW[A[i]]) {
        C[X[i]] += H;
        usedW[A[i]] = true;
        W--;
      }
    }
  }
  C[0] += H * W;
  vector<pair<int,ll>> res;
  rep(i,2e5+1) {
    if (C[i] > 0)
      res.push_back({i,C[i]});
  }
  print(res.size());
  fore(e,res) {
    print(e.first, e.second);
  }
  return 0;
}