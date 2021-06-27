#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

typedef struct apple {
  int value;
  int color;
}apple;

//降順
int des(const void *a, const void *b)
{
  return ((apple *)b)->value - ((apple *)a)->value;
}

int main() {
  int x,y,a,b,c;
  scanf("%d%d%d%d%d", &x, &y, &a, &b, &c);
  apple app[a+b+c];
  for (int i=0; i<a; i++) {
    scanf("%d", &(app[i].value));
    app[i].color = 0;
  }
  for (int i=0; i<b; i++) {
    scanf("%d", &(app[a+i].value));
    app[a+i].color = 1;
  }
  for (int i=0; i<c; i++) {
    scanf("%d", &(app[a+b+i].value));
    app[a+b+i].color = 2;
  }
  qsort(app, a+b+c, sizeof(apple), des);
  int cnt[3] = {};
  long ans = 0;
  for (int i=0; i<a+b+c; i++) {
    if (cnt[0]+cnt[1]+cnt[2] == x+y)
      break;
    if (app[i].color == 0) {
      if (cnt[0] >= x)
        continue;
      cnt[0]++;
      ans += app[i].value;
    } else if (app[i].color == 1) {
      if (cnt[1] >= y)
        continue;
      cnt[1]++;
      ans += app[i].value;
    } else {
      cnt[2]++;
      ans += app[i].value;
    }
  }
  printf("%ld\n", ans);
  return 0;
}
