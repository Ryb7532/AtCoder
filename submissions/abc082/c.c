#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
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
  for (int i=0; i<n; i++)
    scanf("%d", a+i);
  qsort(a, n, sizeof(int), acs);
  int cnt = 0, j = a[0], ans = 0;
  for (int i=0; i<n; i++) {
    if (a[i] == j) {
      if (cnt < j) cnt++;
      else ans++;
    } else {
      if (cnt < j)
        ans += cnt;
      cnt = 1;
      j = a[i];
    }
  }
  if (cnt < j)
    ans += cnt;
  printf("%d\n", ans);
  return 0;
}
