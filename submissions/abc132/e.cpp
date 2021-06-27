#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
using Edge = struct{
  int to;
  int a;
  int time;
};
vector<int> edge[100000];
bool used[3][100000];
int ans = -1, S, T;
queue<Edge> q;

void bfs() {
  while (!q.empty()) {
    Edge e = q.front();
    q.pop();
    int eto, ea, t;
    eto = e.to;
    ea = e.a;
    t = e.time;
    if (eto == T && ea == 0) {
      ans = t/3;
      return ;
    }
    for (auto &n: edge[eto]) {
      if (used[(ea+1)%3][n])
        continue;
      q.push({n, (ea+1)%3, t+1});
      used[(ea+1)%3][n] = true;
    }
  }
  return ;
}

int main() {
  int N, M, u, v;
  cin >> N >> M;
  for (int i=0; i<M; i++) {
    cin >> u >> v;
    u--;
    v--;
    for (int j=0; j<3; j++)
      edge[u].push_back(v);
  }
  cin >> S >> T;
  S--;
  T--;
  for (int i=0; i<N; i++)
    for (int j=0; j<3; j++)
      used[j][i] = false;
  used[0][S] = true;
  for (auto &n: edge[S]) {
    q.push({n, 1, 1});
    used[1][n] = true;
  }
  bfs();
  cout << ans << endl;
  return 0;
}
