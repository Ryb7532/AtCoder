#include <bits/stdc++.h>
using namespace std;
vector<int> edge[100000];
int d[2][100000];

void dfs(int idx, int n, int p, int dis) {
  d[idx][n] = dis;
  for (auto &e: edge[n]) {
    if (e == p)
      continue;
    dfs(idx, e, n, dis+1);
  }
  return ;
}

int main() {
  int N, a, b;
  cin >> N;
  for (int i=0; i<N-1; i++) {
    cin >> a >> b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  dfs(0, 0, -1, 0);
  dfs(1, N-1, -1, 0);
  int cnt = 0;
  for (int i=0; i<N; i++) {
    if (d[0][i] > d[1][i])
      continue;
    cnt++;
  }
  if (N - 2*cnt < 0)
    cout << "Fennec\n";
  else
    cout << "Snuke\n";
  return 0;
}