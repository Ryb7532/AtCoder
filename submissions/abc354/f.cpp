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
  int T;
  cin >> T;
  const int INF = 1e9+5;
  rep(T) {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> dp(N, INF);
    vector<int> L(N), R(N);
    int l = 0;
    rep(i,N) {
      cin >> A[i];
      auto it = lower_bound(all(dp), A[i]);
      if (*it == INF)
        l++;
      L[i] = it-dp.begin();
      *it = A[i];
    }
    dp.assign(N, INF);
    rrep(i,N) {
      auto it = lower_bound(all(dp), -A[i]);
      R[i] = it-dp.begin();
      *it = -A[i];
    }
    vector<int> res;
    rep(i,N) {
      if (L[i]+R[i] == l-1)
        res.push_back(i+1);
    }
    print(res.size());
    printall(res);
  }
  return 0;
}