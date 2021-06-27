#include <stdio.h>

int main() {
  int n, l;
  scanf("%d%d", &n, &l);
  if (l<=0 && l+n-1>=0) {
    printf("%d\n", n*(2*l+n-1)/2);
  } else if (l>0) {
    printf("%d\n", (n-1)*(2*l+n)/2);
  } else {
    printf("%d\n", (n-1)*(2*l+n-2)/2);
  }
  return 0;
}
