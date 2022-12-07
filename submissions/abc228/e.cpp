#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


const ll mod = 998244353;


int main() {
  ll N,K,M;
  cin >> N >> K >> M;
  M %= mod;
  if (M == 0) {
    print(0);
    return 0;
  }
  K %= mod-1;
  ll r = 1, res = 1;
  while (N != 0) {
    if (N%2) {
      r *= K;
      r %= mod-1;
    }
    K *= K;
    K %= mod-1;
    N /= 2;
  }
  while (r != 0) {
    if (r%2) {
      res *= M;
      res %= mod;
    }
    M *= M;
    M %= mod;
    r /= 2;
  }
  print(res);
  return 0;
}
