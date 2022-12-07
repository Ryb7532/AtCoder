#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>
//#include <math.h>
#include <stdbool.h>

#define N 100000

//グラフ
typedef struct edge{
  int next;
  int length;
} edge;

edge e[N+1];
bool visited[N+1];
int st[N+1];

void init(int n) {
  for (int i=0; i<n+1; i++) {
    e[i].next = 0;
    e[i].length = 0;
    visited[i] = 0;
    st[i] = 0;
  }
}

void uniteGraph(int a, int b, int length) {
  if (e[a].next == 0) {
    e[a].next = b;
    e[a].length = length%2;
  } else if (e[b].next == 0) {
    e[b].next = a;
    e[b].length = length%2;
  } else {
    int nb = e[b].next;
    int lb = e[b].length;
    e[b].next = a;
    e[b].length = length%2;
    uniteGraph(b, nb, lb);
  }
}

int dfs(int n) {
  if (visited[n]) return st[n];
  if (e[n].next == 0) {
    st[n] = 0;
    visited[n] = true;
    return st[n];
  }
  int b = dfs(e[n].next);
  st[n] = (b+e[n].length)%2;//use b
  visited[n] = true;
  return st[n];
} //DepthFirstSearch

int main() {
  int n;
  scanf("%d", &n);
  int u, v, w;
  init(n);
  for (int i=0; i<n-1; i++) {
    scanf("%d%d%d", &u, &v, &w);
    uniteGraph(u, v, w);
  }
  for (int i=0; i<n; i++) {
    printf("%d\n", dfs(i+1));
  }
  return 0;
}
