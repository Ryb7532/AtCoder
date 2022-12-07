//WA
#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define Stand 8000

int main() {
  char s[8005];
  int x, y;
  scanf("%s%d%d", s, &x, &y);
  int v[2][16001] = {}, h[2][16001] = {}, len = strlen(s), k = 0, cntT = 0, cntF = 0, stv = 0, sth = 0;
  s[len] = 'T';
  while (s[k] == 'F')
    k++;
  v[0][Stand+k] = 1;
  h[0][Stand] = 1;
  for (; k<=len; k++) {
    if (s[k] == 'T') {
      if (cntT%2) {
        for (int i=0; i<16001; i++) {
          if (i >= cntF && h[sth][i - cntF])
            h[(sth + 1) % 2][i] = 1;
          else if (i < 16001 - cntF && h[sth][i + cntF])
            h[(sth + 1) % 2][i] = 1;
          else
            h[(sth + 1) % 2][i] = 0;
        }
        sth++;
        sth %= 2;
      } else {
        for (int i=0; i<16001; i++) {
          if (i >= cntF && v[stv][i - cntF])
            v[(stv + 1) % 2][i] = 1;
          else if (i < 16001 - cntF && v[stv][i + cntF])
            v[(stv + 1) % 2][i] = 1;
          else
            v[(stv + 1) % 2][i] = 0;
        }
        stv++;
        stv %= 2;
      }
      cntT++;
      cntF = 0;
    } else {
      cntF++;
    }
  }
  if (h[sth][Stand+y] && v[stv][Stand+x])
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
