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
  while (b!=0) {
    a %= b;
    swap(a,b);
  }
  return a;
}

int main() {
  ll N,M;
  string S,T;
  cin >> N >> M >> S >> T;
  ll G = gcd(N,M);
  ll L = N/G*M;
  bool flag = true;
  for (ll i=0; i<G; i++) {
    if (S[N/G * i] != T[M/G * i])
      flag = false;
  }
  print((flag ? L : -1));
  return 0;
}
