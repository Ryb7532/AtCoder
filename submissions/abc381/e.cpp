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
  int N,Q;
  string S;
  scan(N,Q,S);
  vector<int> L(N+1, 0), R(N+1, 0), P;
  rep(i,N) {
    if (S[i] == '1') {
      L[i+1]++;
    } else if (S[i] == '2') {
      R[i]++;
    } else {
      P.push_back(i);
    }
  }
  P.push_back(N);
  rep(i,N) L[i+1] += L[i];
  rrep(i,N) R[i] += R[i+1];
  rep(_,Q) {
    int l, r;
    scan(l,r);
    l--;
    if (*lower_bound(all(P), l) >= r) {
      print(0);
      continue;
    }
    int oor_ones = L[l], oor_twos = R[r];
    int lb = 0, ub = 1e5;
    while (ub-lb > 1) {
      int m = (ub+lb)/2;
      int idx = lower_bound(all(L), oor_ones+m) - L.begin();
      auto it = lower_bound(all(P), max(idx-1, l));
      if (*it < r && R[*it]-oor_twos >= m) lb = m;
      else ub = m;
    }
    print(2*lb+1);
  }
  return 0;
}