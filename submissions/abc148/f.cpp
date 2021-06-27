#include <bits/stdc++.h>
using namespace std;
vector<int> edge[100000];
int dis_u[100000] = {}, dis_v[100000] = {};

void dfs_u(int n, int p, int dis) {
  dis_u[n] = dis;
  for (auto &e: edge[n]) {
    if (e == p)
      continue;
    dfs_u(e, n, dis+1);
  }
  return ;
}

void dfs_v(int n, int p, int dis) {
  dis_v[n] = dis;
  for (auto &e: edge[n]) {
    if (e == p)
      continue;
    dfs_v(e, n, dis+1);
  }
  return ;
}

int main() {
  int N, u, v;
  cin >> N  >> u >> v;
  u--;
  v--;
  int A, B;
  for (int i=0; i<N-1; i++) {
    cin >> A >> B;
    A--;
    B--;
    edge[A].push_back(B);
    edge[B].push_back(A);
  }
  dfs_u(u, -1, 0);
  dfs_v(v, -1, 0);
  int ans = 0;
  for (int i=0; i<N; i++) {
    if (dis_u[i]<dis_v[i]) {
      ans = max(ans, dis_v[i]-1);
    }
  }
  cout << ans << endl;
  return 0;
}
