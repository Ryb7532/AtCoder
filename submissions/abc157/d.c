#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define N 100001

int parent[N];

void uft_init(int n)
{
  for (int i = 0; i < n; i++)
    parent[i] = -1;
}

int uft_root(int a)
{
  if (parent[a] < 0)
    return a;
  return parent[a] = uft_root(parent[a]);
}

int uft_size(int a)
{
  if (parent[a] >= 0)
    return uft_size(parent[a]);
  return -parent[a];
}

void uft_unite(int a, int b)
{
  int ra = uft_root(a), rb = uft_root(b);
  if (ra == rb)
    return;
  if (uft_size(ra) > uft_size(rb))
  {
    parent[ra] += parent[rb];
    parent[rb] = ra;
  }
  else
  {
    parent[rb] += parent[ra];
    parent[ra] = rb;
  }
}

int main() {
  int n, m, k, a, b;
  scanf("%d%d%d", &n, &m, &k);
  uft_init(n);
  int cnt[n];
  for (int i = 0; i < n; i++)
    cnt[i] = 0;
  for (int i=0; i<m; i++) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    uft_unite(a, b);
    cnt[a]++;
    cnt[b]++;
  }
  for (int i=0; i<k; i++) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    if (uft_root(a) == uft_root(b)) {
      cnt[a]++;
      cnt[b]++;
    }
  }
  /*
  for (int i=0; i<n; i++)
    printf("%d %d\n", uft_size(i), cnt[i]);*/
  for (int i=0; i<n; i++)
    printf("%d ", uft_size(i)-cnt[i]-1);
  printf("\n");
  return 0;
}
