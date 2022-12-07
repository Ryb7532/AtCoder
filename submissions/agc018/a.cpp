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


ll gcd(ll a, ll b) {
  while (b != 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int main() {
  int N,K;
  cin >> N >> K;
  vector<ll> A(N);
  ll M = 0;
  ll g = 0;
  rep(i,N) {
    cin >> A[i];
    M = max(M,A[i]);
    g = gcd(g, A[i]);
  }
  if (M<K) {
    print("IMPOSSIBLE");
    return 0;
  }
  if (K%g != 0) {
    print("IMPOSSIBLE");
    return 0;
  }
  print("POSSIBLE");
  return 0;
}
