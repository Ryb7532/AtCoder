#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  int a[n], max = 0;
  for (int i=0; i<n; i++) scanf("%d", a+i);
  for (int i=0; i<n-1; i++) for (int j=i+1; j<n; j++) max = (abs(a[i]-a[j]) > max) ? abs(a[i]-a[j]) : max;
  printf("%d\n", max);
  return 0;
}
