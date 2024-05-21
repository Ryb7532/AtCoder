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
  int N,M,L;
  cin >> N >> M >> L;
  vector<ll> A(N);
  vector<pair<ll,int>> B(M);
  vector<set<int>> C(N);
  rep(i,N) {
    cin >> A[i];
  }
  rep(i,M) {
    int p;
    cin >> p;
    B[i] = {p, i};
  }
  rep(i,L) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    C[a].insert(b);
  }
  sort(rall(B));
  ll res = 0;
  rep(i,N) {
    if (C[i].size() == M)
      continue;
    ll a = A[i], b = 0;
    int j = 0;
    while (j < M) {
      if (C[i].find(B[j].second) != C[i].end()) {
        j++;
        continue;
      }
      b = B[j].first;
      break;
    }
    chmax(res, a+b);
  }
  print(res);
  return 0;
}