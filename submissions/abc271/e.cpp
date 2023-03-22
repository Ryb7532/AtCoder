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


int main() {
  const ll maxC = 2e15;
  int N,M,K;
  cin >> N >> M >> K;
  vector<int> A(M), B(M);
  vector<ll> C(M);
  rep(i,M) {
    cin >> A[i] >> B[i] >> C[i];
  }
  vector<ll> dp(N+1, maxC);
  dp[1] = 0;
  rep(_,K) {
    int E;
    cin >> E;
    E--;
    int a = A[E], b = B[E];
    dp[b] = min(dp[b], dp[a]+C[E]);
  }
  print((dp[N] == maxC ? -1 : dp[N]));
  return 0;
}
