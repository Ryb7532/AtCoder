#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

//GCD
int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  int k;
  scanf("%d", &k);
  long ans = 0;
  for (int i=0; i<k; i++) {
    for (int j=0; j<k; j++) {
      int tmp = gcd(i+1, j+1);
      for (int l=0; l<k; l++) {
        ans += gcd(tmp, l+1);
      }
    }
  }
  printf("%ld\n", ans);
  return 0;
}
