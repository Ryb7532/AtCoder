#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
vector<int> edge[100000];
int N, K;
long ans;

void dfs(int n, int p) {
  int k;
  if (p == -1) {
    ans = K;
    k = K-1;
  }
  else
    k = K-2;
  for (auto &e: edge[n]) {
    if (e == p)
      continue;
    ans *= k;
    ans %= MOD;
    dfs(e, n);
    k--;
  }
  return ;
}

int main() {
  int a, b;
  cin >> N >> K;
  for (int i=0; i<N-1; i++) {
    cin >> a >> b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  dfs(0, -1);
  cout << ans << endl;
  return 0;
}
