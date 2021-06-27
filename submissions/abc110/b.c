#include <stdio.h>

int main() {
  int n, m, x, y;
  scanf("%d%d%d%d", &n, &m, &x, &y);
  int a, maxx=-101, miny=101;
  for (int i=0; i<n; i++) {
    scanf("%d", &a);
    maxx = (a>maxx) ? a : maxx;
  }
  for (int i=0; i<m; i++) {
    scanf("%d", &a);
    miny = (a<miny) ? a : miny;
  }
  if (x<=maxx&&maxx<miny&&miny<=y) printf("No War");
  else printf("War");
  return 0;
}
