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
  int K;
  cin >> K;
  vector<ll> A(K);
  rep(i,K) {
    cin >> A[i];
  }
  ll m = 2, M = 2;
  for (int i=K-1; i>=0; i--) {
    ll new_m = (m+A[i]-1)/A[i] * A[i];
    ll new_M = (M/A[i]+1) * A[i] - 1;
    m = new_m;
    M = new_M;
    if (M<m) {
      print(-1);
      return 0;
    }
  }
  print(m << ' ' << M);
  return 0;
}
