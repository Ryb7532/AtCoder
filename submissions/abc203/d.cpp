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
  int N,K;
  cin >> N >> K;
  vec<vec<ll>> A(N,vec<ll>(N));
  rep(i,N) {
    rep(j,N) {
      cin >> A[i][j];
    }
  }
  ll u=1e9+1,l=0;
  while (u-l>1) {
    ll m = (u+l)/2;
    vec<vec<int>> B(N+1,vec<int>(N+1,0));
    rep(i,N) {
      rep(j,N) {
        B[i+1][j+1] = (A[i][j]<m);
        B[i+1][j+1] += B[i][j+1] + B[i+1][j];
        B[i+1][j+1] -= B[i][j];
      }
    }
    bool flag = false;
    for (int i=K; i<=N; i++) {
      for (int j=K; j<=N; j++) {
        int cnt = B[i][j];
        cnt -= B[i][j-K] + B[i-K][j];
        cnt += B[i-K][j-K];
        if (K*K-cnt < K*K/2+1)
          flag = true;
      }
    }
    if (flag)
      u = m;
    else
      l = m;
  }
  print(l);
  return 0;
}
