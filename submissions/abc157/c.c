#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  int c[n], s, tmp, ans = 0;
  for (int i = 0; i < n; i++)
    c[i] = -1;
  for (int i = 0; i < m; i++)
  {
    scanf("%d%d", &s, &tmp);
    s--;
    if (c[s] == -1)
      c[s] = tmp;
    else if (c[s] != tmp)
      ans = -1;
  }
  if (ans == -1)
    printf("-1\n");
  else if (n == 1) {
    if (c[0]==-1)
      printf("0\n");
    else
      printf("%d\n", c[0]);
  }
  else if (c[0] == 0)
    printf("-1\n");
  else
  {
    if (c[0] == -1)
      ans = 1;
    else
      ans = c[0];
    for (int i = 1; i < n; i++)
    {
      ans *= 10;
      if (c[i] != -1)
        ans += c[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}
