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
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << ((f) ? Yes : No) << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}
template<typename... Args> void print(const Args... args) {(cout << ... << (cout << ' ', args)) << endl;}

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  map<int,vector<int>> sameA, sameB;
  rep(i,N) {
    cin >> A[i] >> B[i];
    sameA[A[i]].push_back(i);
    sameB[B[i]].push_back(i);
  }
  vector<int> win(1ll<<N,-1);
  for (ll i=0; i<(1ll<<N); i++) {
    int cnt = 0;
    rep(j,N) {
      if (i>>j & 1)
        cnt++;
    }
    if ((N-cnt)%2)
      continue;
    int w = (N-cnt)/2%2;
    bool f = false;
    rep(j,N) {
      if ((i>>j) & 1) {
        fore(k,sameA[A[j]]) {
          if (k == j || ((i>>k) & 1) == 0)
            continue;
          if (win[i-(1ll<<j)-(1ll<<k)] == w)
            f = true;
        }
        fore(k,sameB[B[j]]) {
          if (k == j || ((i>>k) & 1) == 0)
            continue;
          if (win[i-(1ll<<j)-(1ll<<k)] == w)
            f = true;
        }
      }
    }
    if (!f)
      w = 1-w;
    win[i] = w;
  }
  print(win.back() == 0 ? "Takahashi" : "Aoki");
  return 0;
}