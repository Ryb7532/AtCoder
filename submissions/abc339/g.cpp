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
  int N,Q;
  cin >> N;
  vector<ll> A(1<<18, 1e18);
  rep(i,N) {
    cin >> A[i];
  }
  N = 1<<18;
  vector<vector<ll>> seg(1<<19), sum(1<<19);
  rep(i,19) {
    rep(j,1<<i) {
      seg[(1<<i) + j].resize(1<<(18-i));
      sum[(1<<i) + j].assign((1<<(18-i))+1, 0);
    }
  }
  rep(i,N) {
    seg[N+i][0] = A[i];
    sum[N+i][1] = A[i];
  }
  rrep(i,1,N) {
    int l = 0, r = 0;
    int s = seg[i].size();
    while (l+r < s) {
      if (l == s/2) {
        seg[i][l+r] = seg[2*i+1][r];
        r++;
      } else if (r == s/2) {
        seg[i][l+r] = seg[2*i][l];
        l++;
      } else {
        if (seg[2*i][l] < seg[2*i+1][r]) {
          seg[i][l+r] = seg[2*i][l];
          l++;
        } else {
          seg[i][l+r] = seg[2*i+1][r];
          r++;
        }
      }
    }
    rep(j,s) {
      sum[i][j+1] = sum[i][j] + seg[i][j];
    }
  }
  cin >> Q;
  ll B = 0;
  rep(Q) {
    ll L, R, X;
    cin >> L >> R >> X;
    L ^= B;
    R ^= B;
    X ^= B;
    L--;
    ll res = 0;
    for (L+=N, R+=N; L<R; L>>=1, R>>=1) {
      if (L&1) {
        int i = lower_bound(all(seg[L]), X+1) - seg[L].begin();
        res += sum[L][i];
        L++;
      }
      if (R&1) {
        R--;
        int i = lower_bound(all(seg[R]), X+1) - seg[R].begin();
        res += sum[R][i];
      }
    }
    print(res);
    B = res;
  }
  return 0;
}