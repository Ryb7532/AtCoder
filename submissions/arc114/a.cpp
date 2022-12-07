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


ll GCD(ll a, ll b) {
  while (b != 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}

vector<ll> prime = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

int main() {
  int N;
  cin >> N;
  vector<ll> X(N);
  rep(i,N) {
    cin >> X[i];
  }
  ll res = 1e18;
  for (int i=1; i<(1<<15); i++) {
    ll tmp = 1;
    rep(j,15) {
      if ((1<<j) & i){
        tmp *= prime[j];
      }
    }
    bool flag = true;
    rep(j,N) {
      ll g = GCD(X[j], tmp);
      if (g == 1) {
        flag = false;
      }
    }
    if (!flag)
      continue;
    res = min(res, tmp);
  }
  print(res);
  return 0;
}
