#include <bits/stdc++.h>
using namespace std;
vector<int> edge[8];
bool used[8];
int ans = 0, N;

void dfs(int n, int p) {
  if (used[n])
    return ;
  used[n] = true;
  for (auto &e: edge[n]) {
    if (e == p)
      continue;
    dfs(e, n);
  }
  bool chk = true;
  for (int i=0; i<N; i++)
    if (!used[i])
      chk = false;
  if (chk)
    ans++;
  used[n] = false;
}

int main() {
  int M, a, b;
  cin >> N >> M;
  for (int i=0; i<M; i++) {
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
