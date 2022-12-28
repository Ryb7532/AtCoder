#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


ll GCD(ll a, ll b) {
  if (b==0) {
    return a;
  }
  return GCD(b, a%b);
}


int main() {
  ll N,A,B;
  cin >> N >> A >> B;
  ll res = N * (N+1) / 2;
  ll gcd = GCD(A,B);
  ll lcmAB = A * B / gcd;
  ll dA = N/A, dB = N/B, dAB = N/lcmAB;
  res -= A * (dA * (dA+1) / 2);
  res -= B * (dB * (dB+1) / 2);
  res += lcmAB * (dAB * (dAB+1) / 2);
  print(res);
  return 0;
}
