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


bool isPrime(ll n) {
  if (n == 1) return false;
  for (ll i=2; i*i<=n; i++) {
    if (n%i == 0) {
      return false;
    }
  }
  return true;
}


int main() {
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  bool win = false;
  for (int i=A; i<=B; i++) {
    bool flag = false;
    for (int j=C; j<=D; j++) {
      if (isPrime(i+j))
        flag = true;
    }
    if (!flag)
      win = true;
  }
  print((win ? "Takahashi": "Aoki"));
  return 0;
}
