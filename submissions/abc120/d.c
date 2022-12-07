//WA
#include <stdio.h>

#define N 100001

//UnionFind木(葉より根の方が値が小さい)
typedef struct UnionFindTree{
  int parent;
  int size;
} uft;

uft t[N];

void init(int n) {
  for (int i=0; i<n; i++) {
    t[i].parent = i;
    t[i].size = 1;
  }
}

int root(int a) {
  if (t[a].parent == a) return a;
  else return root(t[a].parent);
}

void unite(int a, int b) {
  int ra=root(a), rb=root(b);
  if (ra == rb) return ;
  if (ra < rb) {
    t[rb].parent = ra;
    t[ra].size += t[rb].size;
  } else {
    t[ra].parent = rb;
    t[rb].size += t[ra].size;
  }
}

int main() {
  long n, m;
  scanf("%ld%ld", &n, &m);
  int a[m], b[m]; long ans[m+1];
  ans[m] = n*(n-1)/2;
  for (int i=0; i<m; i++) scanf("%d%d", a+i, b+i);
  init(n);
  for (int i=m-1; i>=0; i--) {
    int ra=root(a[i]-1), rb=root(b[i]-1);
    if (ra==rb) ans[i] = ans[i+1];
    else {
      ans[i] = ans[i+1]-(t[ra].size*t[rb].size);
      unite(ra, rb);
    }
  }
  for (int i=0; i<m; i++) printf("%ld\n", ans[i+1]);
  return 0;
}
