#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

#define N 100000

//UnionFind木
int parent[N];
void init(int n) {
  for (int i=0; i<n; i++) parent[i] = -1;
}
int root(int a) {
  if (parent[a] < 0) return a;
  else return parent[a] = root(parent[a]);
}
int size(int a) {
  return -parent[a];
}
void unite(int a, int b) {
  int ra=root(a), rb=root(b);
  if (ra == rb) return ;
  if (size(ra) > size(rb)) {
    parent[ra] += parent[rb];
    parent[rb] = ra;
  } else {
    parent[rb] += parent[ra];
    parent[ra] = rb;
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int p[n], x, y;
  for (int i=0; i<n; i++) scanf("%d", p+i);
  init(n);
  for (int i=0; i<m; i++) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    unite(x, y);
  }
  int ans=0;
  for (int i=0; i<n; i++) {
    if (root(i) == root(p[i]-1)) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
