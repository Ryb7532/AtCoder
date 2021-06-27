#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define N 55
#define M 50

int parent[M][N];

void uft_init(int n, int m)
{
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      parent[i][j] = -1;
}

int uft_root(int a, int b)
{
  if (parent[a][b] < 0)
    return b;
  return parent[a][b] = uft_root(a, parent[a][b]);
}

int uft_size(int a, int b)
{
  return -parent[a][b];
}

void uft_unite(int a, int b, int c)
{
  int rb = uft_root(a, b), rc = uft_root(a, c);
  if (rb == rc)
    return;
  if (uft_size(a, rb) > uft_size(a, rc))
  {
    parent[a][rb] += parent[a][rc];
    parent[a][rc] = rb;
  }
  else
  {
    parent[a][rc] += parent[a][rb];
    parent[a][rb] = rc;
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a[m], b[m], ans = 0;
  for (int i=0; i<m; i++)
    scanf("%d%d", a+i, b+i);
  uft_init(n, m);
  for (int i=0; i<m; i++) {
    for (int j=0; j<m; j++) {
      if (i == j)
        continue;
      uft_unite(i, a[j]-1, b[j]-1);
    }
    int cnt = 0;
    for (int j=0; j<n; j++)
      if (parent[i][j] < 0)
        cnt++;
    if (cnt > 1)
      ans++;
  }
  printf("%d\n", ans);
  return 0;
}
