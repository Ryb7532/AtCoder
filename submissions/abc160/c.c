#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define Max(a, b) ((a > b) ? a : b)

int main() {
  int k, n;
  scanf("%d%d", &k, &n);
  int a[n];
  for (int i=0; i<n; i++)
    scanf("%d", a+i);
  int dis = k-a[n-1]+a[0];
  for (int i=0; i<n-1; i++)
    dis = Max(dis, abs(a[i]-a[i+1]));
  printf("%d\n", k-dis);
  return 0;
}
