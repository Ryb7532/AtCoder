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


int main() {
  ll N,D;
  cin >> N >> D;
  vector<pair<ll,ll>> W(N);
  rep(i,N) {
    cin >> W[i].first >> W[i].second;
  }
  sort(all(W));
  int ans = 1;
  ll r=1e9;
  rep(i,N) {
    if (W[i].first < r) {
      r = min(r, W[i].second);
    } else if (W[i].first < r+D) {
      continue;
    } else {
      ans++;
      r = W[i].second;
    }
  }
  print(ans);
  return 0;
}
