#include <stdio.h>
#include <stdlib.h>

int cmp(const void *x, const void *y) {
  return *(int *)x-*(int *)y;
}

int main() {
  int n, m, k=0; long long int ans = 0;
  scanf("%d%d", &n, &m);
  int a[n], b[30];
  for (int i=0; i<n; i++) scanf("%d", a+i);
  for (int i=0; i<30; i++) b[i]=0;
  qsort(a, n, sizeof(int), cmp);
  for (int i=0; i<n; i++) {
    for (int j=k; j<30; j++) {
      if (a[i]>=(1<<j) && a[i]<(1<<(j+1))) {
        b[j]++;
        k=j;
      }
    }
  }
  for (int i=29; i>=0; i--) {
    if (b[i] == 0) continue;
    if (m <= 0) break;
    int l = (m<b[i]) ? m : b[i];
    for (int j=0; j<l; j++) {
      a[n-1-j] /= 2;
    }
    b[i-1] += b[i];
    m-=l;
    qsort(a, n, sizeof(int), cmp);
  }
  /*while (m > 0) {
    qsort(a, n, sizeof(int), cmp);
    a[0] /= 2;
    m--;
  }*/
  for (int i=0; i<n; i++) {
    ans += a[i];
  }
  printf("%lld\n", ans);
  return 0;
}
