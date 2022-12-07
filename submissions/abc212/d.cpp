#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  multiset<ll> B;
  ll plus = 0;
  int Q;
  cin >> Q;
  rep(_,Q) {
    int op;
    cin >> op;
    if (op==3) {
      print(*(B.begin())+plus);
      B.erase(B.begin());
      continue;
    }
    ll X;
    cin >> X;
    if (op==1) {
      B.insert(X-plus);
    } else {
      plus += X;
    }
  }
  return 0;
}
