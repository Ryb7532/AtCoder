#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
#define NMAX 100000
int N, M, res[NMAX];
bool used[NMAX];
vector<int> edge[NMAX];
queue<pint> q;

void bfs() {
  res[0] = 0;
  used[0] = true;
  for (auto &e: edge[0])
    q.push({0, e});
  while (!q.empty()) {
    pint w = q.front();
    int p = w.first, n = w.second;
    q.pop();
    if (used[n])
      continue;
    res[n] = p+1;
    used[n] = true;
    for (auto &e: edge[n]) {
      if (used[e])
        continue;
      q.push({n, e});
    }
  }
  return;
}

int main() {
  cin >> N >> M;
  int a, b;
  for (int i=0; i<M; i++) {
    cin >> a >> b;
    a--; b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  bfs();
  cout << "Yes" << endl;
  for (int i=1; i<N; i++)
    cout << res[i] << endl;
  return 0;
}
