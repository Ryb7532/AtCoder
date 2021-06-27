#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
vector<int> edge[100000];
int N;
ll dp[100000][2];

void dfs(int n, int p) {
  ll cnt0 = 1, cnt1 = 1;
  for (auto &e: edge[n]) {
    if (e == p)
      continue;
    dfs(e, n);
    cnt0 *= dp[e][1];
    cnt0 %= MOD;
    cnt1 *= dp[e][0];
    cnt1 %= MOD;
  }
  dp[n][0] = cnt0;
  dp[n][1] = (cnt0 + cnt1)%MOD;
  return ;
}

int main() {
  int a, b;
  cin >> N;
  for (int i=0; i<N-1; i++) {
    cin >> a >> b;
    a--; b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  dfs(0, -1);
  cout << dp[0][1] << endl;
  return 0;
}
