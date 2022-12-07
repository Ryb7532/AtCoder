#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int a, b, c, d, e, f;
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
  int anssw = 0, anss = 0;
  double conct = 0;
  for (int i=0; i<=f; i+=100*a) {
    for (int j=0; j<=f-i; j+=100*b) {
      for (int k=0; k<=f-i-j; k+=c) {
        if ((i+j)/100 * e < k)
          break;
        for (int l=0; l<=f-i-j-k; l+=d) {
          if ((i+j)/100 * e < k + l)
            break;
          double tmp = 100.00*(k+l)/(i+j+k+l);
          if (conct < tmp) {
            conct = tmp;
            anssw = i+j+k+l;
            anss = k+l;
          }
        }
      }
    }
  }
  if (anssw == 0)
    anssw = 100*a;
  printf("%d %d\n", anssw, anss);
  return 0;
}
