#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 1000

bool visiting[MAXN-1][MAXN];
bool visited[MAXN-1][MAXN];

void resetBool() {
  for (int i=0; i<MAXN; i++) {
    for (int j=0; j<MAXN; j++) {
      visiting[i][j] = false;
    }
  }
}

int d[MAXN-1][MAXN];

typedef struct match{
  int a;
  int b;
  struct match *ta;
  struct match *tb;
} match;

match *createMatch(int a, int b, match *ta, match *tb) {
  match *m = malloc(sizeof(match));
  m->a = a;
  m->b = b;
  m->ta = ta;
  m->tb = tb;
  return m;
}

void freeMatch(match *m) {
  if(m!=NULL) free(m);
}

void addTA(match *m, match *ta) {
  if(m!=NULL) m->ta = ta;
}

void addTB(match *m, match *tb) {
  if(m!=NULL) m->tb = tb;
}

match *m[MAXN-1][MAXN];

int dfs(int i, int j) {
  if (visited[i][j]) return d[i][j];
  visiting[i][j] = true;
  if (m[i][j]->ta == NULL && m[i][j]->tb == NULL) {
    d[i][j] = 1;
    visited[i][j] = true;
    visiting[i][j] = false;
    return 1;
  } else if (m[i][j]->ta != NULL && m[i][j]->tb == NULL) {
    if (visiting[m[i][j]->ta->a][m[i][j]->ta->b]) return -1;
    int next = dfs(m[i][j]->ta->a, m[i][j]->ta->b);
    if (next==-1) return -1;
    d[i][j] = next+1;
    visited[i][j] = true;
    visiting[i][j] = false;
    return d[i][j];
  } else if (m[i][j]->ta == NULL && m[i][j]->tb != NULL) {
    if (visiting[m[i][j]->tb->a][m[i][j]->tb->b]) return -1;
    int next = dfs(m[i][j]->tb->a, m[i][j]->tb->b);
    if (next==-1) return -1;
    d[i][j] = next+1;
    visited[i][j] = true;
    visiting[i][j] = false;
    return d[i][j];
  }
  if (visiting[m[i][j]->ta->a][m[i][j]->ta->b] || visiting[m[i][j]->tb->a][m[i][j]->tb->b]) return -1;
  int nexta = dfs(m[i][j]->ta->a, m[i][j]->ta->b);
  int nextb = dfs(m[i][j]->tb->a, m[i][j]->tb->b);
  if (nexta==-1 || nextb==-1) return -1;
  d[i][j] = (nexta > nextb) ? nexta+1 : nextb+1;
  visited[i][j] = true;
  visiting[i][j] = false;
  return d[i][j];
}

int main() {
  int n;
  scanf("%d", &n);
  int a[n-1], ans = 0;
  for (int i=0; i<n-1; i++) {
    for (int j=i+1; j<n; j++) {
      m[i][j] = createMatch(i, j, NULL, NULL);
    }
  }
  for (int i=0; i<n; i++) {
    match *tmp = NULL;
    for (int j=0; j<n-1; j++) scanf("%d", a+j);
    for (int j=n-2; j>=0; j--) {
      if (a[j] > i+1) {
        addTA(m[i][a[j]-1], tmp);
        tmp = m[i][a[j]-1];
      } else {
        addTB(m[a[j]-1][i], tmp);
        tmp = m[a[j]-1][i];
      }
    }
  }
  for (int i=0; i<n-1; i++) {
    for (int j=i+1; j<n; j++) {
      int l = dfs(i, j);
      if (l==-1) {
        printf("-1\n");
        return 0;
      }
      ans = (l > ans) ? l : ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
