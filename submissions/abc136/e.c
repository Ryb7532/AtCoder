#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void *x, const void *y) {
  return *(int *)x - *(int *)y;
}

int main() {
  int n, k, ans = 1;
  scanf("%d%d", &n ,&k);
  int a[n], sum = 0;
  for (size_t i = 0; i < n; i++) {
    scanf("%d", a+i);
    sum += a[i];
  }
  for (size_t i = 1; i < (int)sqrt((double)sum)+1; i++) {
    if (sum%i == 0) {
      int d1 = i, d2 = sum/i;
      int r1[n], r2[n], r1sum = 0, r2sum = 0, cnt = 0;
      for (size_t j = 0; j < n; j++) {
        r1[j] = a[j] % d1;
        r2[j] = a[j] % d2;
        r1sum += r1[j];
        r2sum += r2[j];
      }
      qsort(r1, n, sizeof(int), cmp);
      qsort(r2, n, sizeof(int), cmp);
      for (size_t j = n-r1sum/d1; j < n; j++) {
        cnt += d1-r1[j];
      }
      ans = (cnt <= k) ? d1 : ans;
      cnt = 0;
      for (size_t j = n-r2sum/d2; j < n; j++) {
        cnt += d2-r2[j];
      }
      if (cnt <= k) {
        ans = d2;
        break;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
