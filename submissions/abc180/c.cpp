#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << a << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  ll n;
  cin >> n;
  set<ll> d;
  d.insert(1);
  d.insert(n);
  reps(i,2,sqrtl((ld) n)+0.1) {
    if (n % i == 0) {
      d.insert(i);
      d.insert(n/i);
    }
  }
  while (!d.empty()) {
    ll res = *d.begin();
    print(res);
    d.erase(res);
  }
  return 0;
}
