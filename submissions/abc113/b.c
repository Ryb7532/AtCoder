#include <stdio.h>
#include <float.h>
#include <math.h>

int main() {
  int n, t, a, ans=0;
  scanf("%d", &n);
  scanf("%d %d", &t, &a);
  double tmp, h[n], dif=DBL_MAX;
  for (int i=0; i<n; i++) {
    scanf("%lf", &tmp);
    h[i] = t-tmp*0.006;
    if (dif > fabs(h[i]-a)) {
      ans = i+1;
      dif = fabs(h[i]-a);
    }
  }
  printf("%d\n", ans);
  return 0;
}
