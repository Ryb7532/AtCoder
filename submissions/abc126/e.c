#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <math.h>
#include <stdbool.h>

#define N 100001

typedef struct UnionFindTree{
  int size;
} uft;

uft t[N];
int parent[N];
bool boo[N];
int ans = 0;

void init(int n) {
  for (int i=0; i<n; i++) {
    t[i].size = 1;
    parent[i] = i;
    boo[i] = false;
  }
}

int root(int a) {
  if (parent[a] == a) return a;
  else return parent[a] = root(parent[a]);
}

void unite(int a, int b) {
  int ra=root(a), rb=root(b);
  if (ra == rb) return ;
  if (t[ra].size > t[rb].size) {
    parent[rb] = ra;
    t[ra].size += t[rb].size;
  } else {
    parent[ra] = rb;
    t[rb].size += t[ra].size;
  }
  return ;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  init(n);
  int x, y, z;
  for (int i=0; i<m; i++) {
    scanf("%d%d%d", &x, &y, &z);
    x--;
    y--;
    unite(x, y);
  }
  for (int i=0; i<n; i++) {
    int p = root(i);
    if (boo[p]) continue;
    ans++;
    boo[p] = true;
  }
  printf("%d\n", ans);
  return 0;
}
