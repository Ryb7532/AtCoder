#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  int ans=0;
  for (int i=a; i<b+1; i++) {
    if (i/10000 != i%10) continue;
    if ((i/1000)%10 != (i/10)%10) continue;
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
