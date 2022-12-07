#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

#define Max(a, b) ((a > b) ? a : b)
int n;
long k, a[200000], f[200000];

//昇順
int acs(const void *a, const void *b)
{
  return *(long *)a - *(long *)b;
}

//降順
int des(const void *a, const void *b)
{
  return *(long *)b - *(long *)a;
}

long binary_search(long b, long t)
{
  if (t-b <= 1)
    return t;
  long cnt = 0, mid = (t+b)/2;
  for (int i=0; i<n; i++) {
    if (mid >= a[i]*f[i])
      continue;
    cnt += a[i] - mid/f[i];
  }
  if (cnt > k)
    return binary_search(mid, t);
  return binary_search(b, mid);
}

int main() {
  scanf("%d%ld", &n, &k);
  for (int i=0; i<n; i++)
    scanf("%ld", a+i);
  for (int i=0; i<n; i++)
    scanf("%ld", f+i);
  qsort(a, n, sizeof(long), acs);
  qsort(f, n, sizeof(long), des);
  long maxt = 0, ans;
  for (int i=0; i<n; i++)
    maxt = Max(maxt, a[i]*f[i]);
  ans = binary_search(-1, maxt);
  printf("%ld\n", ans);
  return 0;
}
