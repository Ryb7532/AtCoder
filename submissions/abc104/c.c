#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int d, g;
  scanf("%d%d", &d, &g);
  int p[d], c[d], ans = 1001;
  for (int i=0; i<d; i++) scanf("%d%d", p+i, c+i);
  for (int i=0; i<(1<<d); i++) {
    int point = 0, cnt = 0;
    for (int j=0; j<d; j++) {
      if ((i & (1<<j)) != 0) {
        point += 100*(j+1)*p[j] + c[j];
        cnt += p[j];
      }
    }
    if (g<=point) ans = (ans > cnt) ? cnt : ans;
    else {
      int j=d-1;
      while (((1<<j) & i) != 0 && j>0) j--;
      if ((g-point-1)/(100*(j+1))+1 < p[j]) {
        cnt += (g-point-1)/(100*(j+1))+1;
        ans = (ans > cnt) ? cnt : ans;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
