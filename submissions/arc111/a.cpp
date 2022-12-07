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
  ll N,M;
  cin >> N >> M;
  ll a=1, p=10;
  while (N!=0) {
    if (N%2) {
      a *= p;
      a %= M*M;
    }
    p *= p;
    p %= M*M;
    N >>= 1;
  }
  print(a/M%M);
  return 0;
}
