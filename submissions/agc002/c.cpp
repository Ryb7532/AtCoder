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
  int N,L;
  cin >> N >> L;
  ll p = 0, M = 0;
  int id;
  rep(i,N) {
    ll a;
    cin >> a;
    if (M < a+p) {
      M = a+p;
      id = i;
    }
    p = a;
  }
  if (M < L) {
    print("Impossible");
    return 0;
  }
  print("Possible");
  for (int i=1; i<id; i++) {
    print(i);
  }
  for (int i=N-1; i>=id; i--) {
    print(i);
  }
  return 0;
}
