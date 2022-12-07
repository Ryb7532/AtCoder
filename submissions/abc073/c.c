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
  int ans = 0, p = 0, cnt = 0;
  for (int i=0; i<n; i++) {
    if (p == a[i] && cnt == 0) {
      ans++;
      cnt++;
    } else if (p == a[i] && cnt == 1) {
      ans--;
      cnt--;
    } else {
      ans++;
      cnt = 1;
      p = a[i];
    }
  }
  printf("%d\n", ans);
  return 0;
}
