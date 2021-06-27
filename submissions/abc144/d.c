#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
#include <math.h>

int main() {
  double a, b, x;
  scanf("%lf%lf%lf", &a, &b, &x);
  double ans;
  if (x<a*a*b/2) {
    ans = 180*atan(2*x/(a*b*b))/M_PI;
  } else {
    ans = 180*atan(a*a*a/(2*a*a*b-2*x))/M_PI;
  }
  printf("%lf\n", 90.0-ans);
  return 0;
}
