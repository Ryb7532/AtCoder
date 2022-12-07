#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define N 200000

//降順
int des(const void *a, const void *b)
{
  return *(int *)b - *(int *)a;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int a, cnt[N] = {}, sum = 0;
  for (int i=0; i<n; i++) {
    scanf("%d", &a);
    cnt[a-1]++;
  }
  qsort(cnt, n, sizeof(int), des);
  for (int i=n-1; i>=k; i--)
    sum += cnt[i];
  printf("%d\n", sum);
  return 0;
}
