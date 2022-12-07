#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>
//#include <math.h>

//昇順
int acs(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a[n], s[n+1]; long cnt = 1, ans = 0;
  s[n] = 0;
  for (int i=0; i<n; i++) scanf("%d", a+i);
  for (int i=0; i<n; i++) a[i] %= m;
  s[0] = a[0];
  for (int i=1; i<n; i++) s[i] = (s[i-1] + a[i]) % m;
  qsort(s, n+1, sizeof(int), acs);
  for (int i=1; i<n+1; i++) {
    if (s[i] == s[i-1]) {
      ans += cnt;
      cnt++;
    } else cnt = 1;
  }
  printf("%ld\n", ans);
  return 0;
}
