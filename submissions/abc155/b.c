#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i=0; i<n; i++) scanf("%d", a+i);
  bool check = true;
  for (int i=0; i<n; i++) {
    if (a[i]%2 != 0)
      continue;
    if (a[i]%3 == 0 || a[i]%5 == 0)
      continue;
    check = false;
    break;
  }
  if (check) printf("APPROVED\n");
  else printf("DENIED\n");
  return 0;
}
