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
  int Q;
  cin >> Q;
  queue<ll> A;
  multiset<ll> A_;
  rep(_,Q) {
    int c;
    cin >> c;
    if (c == 1) {
      ll x;
      cin >> x;
      A.push(x);
    } else if (c == 2) {
      if (A_.empty()) {
        ll top = A.front();
        A.pop();
        print(top);
      } else {
        auto it = A_.begin();
        print(*it);
        A_.erase(it);
      }
    } else {
      while(!A.empty()) {
        ll a = A.front();
        A.pop();
        A_.insert(a);
      }
    }
  }
  return 0;
}
