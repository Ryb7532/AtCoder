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
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int N,Q;
  cin >> N >> Q;
  vector<multiset<int>> b2c(N+1);
  vector<set<int>> c2b(2e5+5);
  rep(_,Q) {
    int t,a;
    cin >> t >> a;
    if (t == 1) {
      int b;
      cin >> b;
      b2c[b].insert(a);
      c2b[a].insert(b);
    } else if (t == 2) {
      for (int e: b2c[a]) {
        cout << e << " ";
      }
      cout << endl;
    } else {
      for (int e: c2b[a]) {
        cout << e << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
