//WA
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
#include <limits.h>
//#include <math.h>

typedef struct Enemy{
  int h;
  long x;
}Enemy;

//昇順
int acs(const void *a, const void *b)
{
  return ((Enemy *)a)->x - ((Enemy *)b)->x;
}

//acs, return i such that a[i-1]<=b<a[i] (a[0]<=b<a[n-1])
int binary_search(Enemy *a, int size, int b)
{
  if (size <= 1)
    return size;
  int mid = size / 2;
  if ((a[mid]).x <= b)
    return mid + binary_search(a + mid, size - mid, b);
  else
    return binary_search(a, mid, b);
}

int main() {
  int n, d, a;
  scanf("%d%d%d", &n, &d, &a);
  Enemy e[n+1];
  e[n].x = LONG_MAX;
  for (int i=0; i<n; i++) scanf("%ld%d", &((e[i]).x), &((e[i]).h));
  qsort(e, n, sizeof(Enemy), acs);
  int domain[n];
  for (int i=0; i<n; i++) {
    domain[i] = binary_search(e, n+1, e[i].x+2*d);
  }
  //for (int i=0; i<n; i++) printf("%d ", domain[i]);
  //printf("\n");
  long f[n+1];
  f[n] = 0;
  for (int i=n-1; i>=0; i--) {
    int idx = domain[i];
    if ((f[i+1] - f[idx])*a >= e[i].h) f[i] = f[i+1];
    else f[i] = f[i+1] + (e[i].h-(f[i+1]-f[idx])*a-1)/a + 1;
  }
  //for (int i=0; i<n; i++) printf("%ld ", f[i]);
  printf("%ld\n", f[0]);
  return 0;
}
