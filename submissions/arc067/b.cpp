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
  int N;
  ll A,B;
  cin >> N >> A >> B;
  vector<ll> X(N);
  rep(i,N) {
    cin >> X[i];
  }
  ll res = 0;
  rep(i,N-1) {
    if ((X[i+1]-X[i])*A < B) {
      res += (X[i+1]-X[i])*A;
    } else {
      res += B;
    }
  }
  print(res);
  return 0;
}
