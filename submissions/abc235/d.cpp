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
  ll a,N;
  cin >> a >> N;
  vector<int> res(1e6,-1);
  queue<ll> q;
  res[1] = 0;
  q.push(1);
  while (!q.empty()) {
    ll n = q.front();
    q.pop();
    if (n*a < 1e6 && res[n*a] == -1) {
      res[n*a] = res[n]+1;
      q.push(n*a);
    }
    if (n >= 10 && n%10 != 0) {
      ll pow = 1;
      while (n/pow > 9) {
        pow *= 10;
      }
      ll m = (n%10) * pow + n/10;
      if (m < 1e6 && res[m] == -1) {
        res[m] = res[n]+1;
        q.push(m);
      }
    }
  }
  print(res[N]);
  return 0;
}
