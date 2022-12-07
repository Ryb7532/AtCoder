#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
#define INF 20000000

int N, M, R, d[200][200], r[8], ans = INT_MAX;
bool used[8];

void dfs(int cnt, int las, int dis) {
  if (cnt >= R) {
    if (ans > dis) ans = dis;
    return;
  }
  for (int i=0; i<R; i++) {
    if (!used[i]) {
      used[i] = true;
      if (las == -1) dfs(cnt+1, i, 0);
      else dfs(cnt+1, i, dis + d[r[las]][r[i]]);
      used[i] = false;
    }
  }
  return ;
}

int main() {
  cin >> N >> M >> R;
  for (int i=0; i<R; i++) {
    cin >> r[i];
    r[i]--;
  }
  int A, B, C;
  for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
      d[i][j] = INF;
  for (int i=0; i<N; i++)
    d[i][i] = 0;
  for (int i=0; i<M; i++) {
    cin >> A >> B >> C;
    A--;
    B--;
    if (d[A][B] > C) d[A][B] = d[B][A] = C;
  }
  for (int k=0; k<N; k++)
    for (int i=0; i<N; i++)
      for (int j=0; j<N; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  for (int i=0; i<R; i++)
    used[i] = false;
  dfs(0, -1, 0);
  cout << ans << endl;
  return 0;
}
