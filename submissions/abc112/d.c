#include <stdio.h>

int main() {
  int n, m, l;
  scanf("%d%d", &n, &m);
  for (l = m/n; l>0; l--) {
    int r = m - l*n;
    if (r%l==0) {
      printf("%d\n", l);
      return 0;
    }
  }
  return 0;
}
