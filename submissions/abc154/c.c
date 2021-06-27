#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

//昇順
int acs(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++)
    scanf("%d", a + i);
  qsort(a, n, sizeof(int), acs);
  int pr = 0;
  bool check = true;
  for (int i=0; i<n; i++) {
    if (pr == a[i]) {
      check = false;
      break;
    } else {
      pr = a[i];
    }
  }
  if (check) printf("YES\n");
  else printf("NO\n");
  return 0;
}
