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
  int N,W;
  cin >> N >> W;
  vector<pair<ll,int>> C(N);
  ll ans = 0;
  rep(i,N) {
    cin >> C[i].first >> C[i].second;
  }
  sort(rall(C));
  rep(i,N) {
    ans += C[i].first * min(C[i].second,W);
    W -= C[i].second;
    if (W <= 0)
      break;
  }
  print(ans);
  return 0;
}
