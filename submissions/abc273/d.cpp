#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int H,W,rs,cs,N;
  cin >> H >> W >> rs >> cs >> N;
  map<int,set<int>> R, C;
  rep(_,N) {
    int r,c;
    cin >> r >> c;
    R[r].insert(c);
    C[c].insert(r);
  }
  int Q;
  cin >> Q;
  rep(_,Q) {
    char d;
    int l;
    cin >> d >> l;
    if (d == 'L') {
      auto it = R[rs].lower_bound(cs);
      int limit = 0;
      if (it != R[rs].begin()) {
        limit = *(--it);
      }
      cs = max(limit+1, cs-l);
    } else if (d == 'R') {
      auto it = R[rs].lower_bound(cs+1);
      int limit = W+1;
      if (it != R[rs].end()) {
        limit = *it;
      }
      cs = min(limit-1, cs+l);
    } else if (d == 'U') {
      auto it = C[cs].lower_bound(rs);
      int limit = 0;
      if (it != C[cs].begin()) {
        limit = *(--it);
      }
      rs = max(limit+1, rs-l);
    } else {
      auto it = C[cs].lower_bound(rs+1);
      int limit = H+1;
      if (it != C[cs].end()) {
        limit = *it;
      }
      rs = min(limit-1, rs+l);
    }
    print(rs << " " << cs);
  }
  return 0;
}
