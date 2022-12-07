#include <stdio.h>
#include <stdlib.h>

//降順
int des(const void *a, const void *b) {
  return *(int *)b - *(int *)a;
}

int main() {
  int n;
  scanf("%d", &n);
  int l[n], ans = 0;
  for (int i=0; i<n; i++) scanf("%d", l+i);
  qsort(l, n, sizeof(int), des);
  for (int i=0; i<n-2; i++) {
    for (int j=i+1; j<n-1; j++) {
      int k=j+1;
      while (l[k]>l[i]-l[j] && k<n) {
        ans++;
        k++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
