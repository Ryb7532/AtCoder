#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  double x[n], y[n], sum=0;
  for (int i=0; i<n; i++) scanf("%lf%lf", x+i, y+i);
  int f=1;
  for (int i=1; i<n; i++) f *= i;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      sum += sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))*f;
    }
  }
  sum /= f*n;
  printf("%lf\n", sum);
  return 0;
}
