#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  int a[N];
  for (int i=0; i<N; i++)
    cin >> a[i];
  int dp[N];
  dp[0] = 0; dp[1] = abs(a[1]-a[0]);
  for (int i=2; i<N; i++) {
    dp[i] = min(dp[i-2]+abs(a[i]-a[i-2]), dp[i-1]+abs(a[i]-a[i-1]));
  }
  cout << dp[N-1] << endl;
  return 0;
}
