//after contest WA

#include <stdio.h>
#include <stdbool.h>

#define N 200000

int parent[N];
int c[N]={0};
bool visit[N]={false};
void init(int n) {
  for (int i=0; i<n; i++) parent[i] = -1;
}
int root(int a) {
  if (parent[a] < 0) return a;
  else return root(parent[a]);
}
void unite(int a, int b) {
  int pb = parent[b];
  parent[b] = a;
  if (pb==-1) return ;
  unite(b, pb);
}
int total(int a) {
  if (parent[a]==-1) return c[a];
  if (visit[a]) return c[a];
  c[a] += total(parent[a]);
  visit[a] = true;
  return c[a];
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  init(n);
  int a, b, p, x;
  for (int i=0; i<n-1; i++) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    if (root(b)==0) unite(b, a);
    else unite(a, b);
  }
  for (int i=0; i<q; i++) {
    scanf("%d%d", &p, &x);
    c[p-1]+=x;
  }
  for (int i=0; i<n; i++) {
    printf("%d ", total(i));
  }
  printf("\n");
  return 0;
}
