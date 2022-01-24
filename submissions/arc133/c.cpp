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
  ll H,W,K;
  cin >> H >> W >> K;
  vector<ll> A(H),B(W);
  rep(i,H) {
    cin >> A[i];
  }
  rep(j,W) {
    cin >> B[j];
  }
  ll res = (K-1)*H*W;
  ll c=0,r=0;
  rep(i,H) {
    r += (K - (W+A[i])%K) % K;
  }
  rep(j,W) {
    c += (K - (H+B[j])%K) % K;
  }
  if (r%K != c%K) {
    res = -1;
  } else {
    res -= max(c,r);
  }
  print(res);
  return 0;
}
