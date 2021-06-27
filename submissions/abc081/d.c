#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  int a[n], min = 0, max = 0, mini, maxi, p, pi;
  for (int i=0; i<n; i++) {
    scanf("%d", a+i);
    if (a[i]<min) {
      min = a[i];
      mini = i;
    }
    if (a[i]>max) {
      max = a[i];
      maxi = i;
    }
  }
  if (abs(min)<abs(max)) {
    p = max;
    pi = maxi;
  } else {
    p = min;
    pi = mini;
  }
  max += p;
  min += p;
  printf("%d\n", 2*n-1);
  for (int i=0; i<n; i++) {
    a[i] += p;
    printf("%d %d\n", pi+1, i+1);
  }
  if (min >= 0) {
    for (int i=1; i<n; i++)
      printf("%d %d\n", i, i+1);
  } else {
    for (int i=1; i<n; i++)
      printf("%d %d\n", n-i+1, n-i);
  }
  return 0;
}
