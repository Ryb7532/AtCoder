#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <limits.h>
#include <math.h>

bool primeCheck(int m)
{
  if (m == 1)
    return false;
  if (m == 2)
    return true;
  bool b = true;
  int i;
  for (i = 2; i <= sqrt((double)m)+1; i++)
  {
    if (m % i != 0)
      continue;
    b = false;
    break;
  }
  return b;
}


int main() {
  int q;
  scanf("%d", &q);
  int l[q], r[q];
  for (int i=0; i<q; i++)
    scanf("%d%d", l+i, r+i);
  int f[50001];
  f[0] = 0;
  for (int i=1; i<50001; i++) {
    if (primeCheck(2*i-1)) {
      if (primeCheck(i)) {
        f[i] = f[i-1]+1;
        continue;
      }
    }
    f[i] = f[i-1];
  }
  for (int i=0; i<q; i++) {
    printf("%d\n", f[(r[i]+1)/2] - f[(l[i]-1)/2]);
  }
  return 0;
}
