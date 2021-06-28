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


int main() {
  int N;
  ll C;
  cin >> N >> C;
  ll a, b, c;
  map<ll, ll> cost;
  rep(i,N) {
    cin >> a >> b >> c;
    cost[a] += c;
    cost[b+1] -= c;
  }
  ll res = 0, st = 0, m = 0;
  for (auto &e: cost) {
    res += (e.first-st)*min(m,C);
    st = e.first;
    m += e.second;
  }
  print(res);
  return 0;
}
