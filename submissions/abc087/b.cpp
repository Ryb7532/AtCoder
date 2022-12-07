#include <bits/stdc++.h>
using namespace std;
using Edge = struct{
  int to;
  int dis;
};
vector<Edge> edge[100000];
int x[100000];
bool used[100000];

void dfs(int n, int p, int d) {
  if (used[n])
    return ;
  x[n] = d;
  used[n] = true;
  for (auto &e: edge[n]) {
    if (e.to == p)
      continue;
    dfs(e.to, n, d+e.dis);
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  int L[M], R[M], D[M], l, r, d;
  for (int i=0; i<M; i++) {
    cin >> l >> r >> d;
    l--; r--;
    L[i] = l;
    R[i] = r;
    D[i] = d;
    edge[l].push_back({r, d});
    edge[r].push_back({l, -d});
  }
  for (int i=0; i<N; i++)
    dfs(i, -1, 0);
  for (int i=0; i<M; i++) {
    int xl = x[L[i]], xr = x[R[i]];
    if (xr-xl != D[i]) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}
