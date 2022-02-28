#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
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
  int Q;
  cin >> Q;
  multiset<ll> A;
  rep(_,Q) {
    int op;
    ll x;
    cin >> op >> x;
    if (op == 1) {
      A.insert(x);
    } else {
      int k;
      cin >> k;
      if (op == 2) {
        auto it = A.lower_bound(x+1);
        while (k>0) {
          if (it != A.begin()) {
            it--;
            k--;
          } else {
            break;
          }
        }
        if (k != 0)
          print(-1);
        else
          print((*it));
      } else {
        auto it = A.lower_bound(x);
        k--;
        while (k>0) {
          if (it != A.end()) {
            it++;
            k--;
          } else {
            break;
          }
        }
        if (k != 0 || it == A.end())
          print(-1);
        else
          print((*(it--)));
      }
    }
  }
  return 0;
}
