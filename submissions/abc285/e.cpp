#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"
#define printYorN(f) cout << (f ? Yes : No) << endl


int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  vector<ll> B(N+1);
  B[0] = 0;
  rep(i,N) {
    B[i+1] = B[i] + A[i/2];
  }
  vector<ll> dp(N+1,0);
  rep(i,N) {
    rep(j,N-i) {
      dp[i+1+j] = max(dp[i+1+j], dp[i]+B[j]);
    }
  }
  print(dp[N]);
  return 0;
}
