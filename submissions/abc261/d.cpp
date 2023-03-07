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
  int N,M;
  cin >> N >> M;
  vector<ll> X(N+1),S(N+1, 0);
  vector<pair<int,ll>> B(M);
  rep(i,N) {
    cin >> X[i+1];
  }
  rep(i,M) {
    cin >> B[i].first >> B[i].second;
  }
  sort(all(B));
  rep(i,N) {
    S[i+1] = S[i] + X[i+1];
  }
  rep(i,M-1) {
    B[i+1].second += B[i].second;
  }
  vector<ll> DP(N+5, 0);
  rep(i,M) {
    int c = B[i].first;
    DP[c] = B[i].second + S[c];
  }
  rep(i,N) {
    DP[i+1] = max(DP[i+1], DP[i]+X[i+1]);
    rep(j,M) {
      int c = B[j].first;
      if (i+1+c > N)
        break;
      DP[i+1+c] = max(DP[i+1+c], DP[i]+B[j].second+S[i+1+c]-S[i+1]);
    }
  }
  print(DP[N]);
  return 0;
}
