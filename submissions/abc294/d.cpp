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
  set<int> uncalled, called;
  rep(i,N) {
    uncalled.insert(i+1);
  }
  rep(_,Q) {
    int t;
    cin >> t;
    if (t == 1) {
      int top = *uncalled.begin();
      uncalled.erase(uncalled.find(top));
      called.insert(top);
    } else if (t == 2) {
      int x;
      cin >> x;
      called.erase(called.find(x));
    } else {
      auto top = called.begin();
      cout << *top << " ";
    }
  }
  cout << endl;
  return 0;
}
