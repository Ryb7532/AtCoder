#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
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
  cin >> N;
  vector<int> res(N, 1);
  for (int i=1; i<N; i++) {
    if (res[i] != 1) {
      continue;
    }
    ll n = i+1;
    while (n <= N) {
      for (ll j=1; j*n<=N; j++) {
        res[j*n-1]++;
      }
      n *= i+1;
    }
  }
  cout << res[0];
  rep(i,N-1) {
    cout << " " << res[i+1];
  }
  cout << endl;
  return 0;
}
