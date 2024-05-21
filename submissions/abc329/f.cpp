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
  int N,Q;
  cin >> N >> Q;
  vector<set<int>> B(N);
  rep(i,N) {
    int c;
    cin >> c;
    B[i].insert(c);
  }
  rep(_,Q) {
    int a,b;
    cin >> a >> b;
    a--, b--;
    bool swp = B[a].size() > B[b].size();
    if (swp)
      swap(a,b);
    fore(e,B[a]) {
      B[b].insert(e);
    }
    if (swp) {
      swap(a,b);
      swap(B[a],B[b]);
    }
    B[a].clear();
    print(B[b].size());
  }
  return 0;
}