#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << a << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"

#define INF 1e8
typedef struct{ll x;ll y;ll z;} city;
ll dist(city src, city dst) {
  return abs(dst.x-src.x) + abs(dst.y-src.y) + max(dst.z-src.z, (ll)0);
}

int main() {
  int n;
  cin >> n;
  city c[n];
  rep(i,n) {
    cin >> c[i].x >> c[i].y >> c[i].z;
  }
  ll ans = INF;
  vec<vec<ll>> dp(n, vec<ll>(1<<n, INF));
  dp[0][1] = 0;
  rep1(j,(1<<n)-1) {
    rep(i,n) {
      if (1<<i & j) continue;
      rep(k,n) {
        if (1<<k & j)
          dp[i][(1<<i)+j] = min(dp[i][(1<<i)+j], dp[k][j]+dist(c[k], c[i]));
      }
    }
  }
  rep(i,n) {
    ans = min(ans, dp[i][(1<<n)-1]+dist(c[i], c[0]));
  }
  print(ans);
  return 0;
}
