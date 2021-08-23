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


ll gcd(ll a, ll b) {
  while (b!=0) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int main() {
  int N;
  cin >> N;
  ll lcm = 1;
  for (int i=2; i<=N; i++) {
    ll g = gcd(lcm,i);
    lcm *= i/g;
  }
  print(lcm+1);
  return 0;
}
