#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define min(a, b) (a < b ? a : b)

int main()
{
  int a, b, c, x;
  scanf("%d %d %d %d", &a, &b, &c, &x);
  int ans = 0;
  for (int i = 0; i <= min(a, x / 500); i++)
  {
    for (int j = 0; j <= min(b, (x - 500 * i) / 100); j++)
    {
      if ((x - 500 * i - 100 * j) / 50 <= c)
        ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
