#include <stdio.h>
#include <stdlib.h>

typedef struct parttime{
  int day;
  int money;
}pt;

int cmp_day(const void *x, const void *y) {
  int xd = ((pt *)x)->day, yd = ((pt *)y)->day;
  if (xd == yd) return ((pt *)y)->money - ((pt *)x)->money;
  return xd - yd;
}

void msort(pt *A, pt *B, int left, int right) {
  if (left != 0) {
    int i=0, j=left, k=0;
    while (i<left && j<right+left) {
      if (A[i].money > A[j].money) {
        B[k++] = A[i++];
      } else {
        B[k++] = A[j++];
      }
    }
    if (i == left) {
    while (j < right+left) {
        B[k++] = A[j++];
      }
    } else {
      while (i < left) {
        B[k++] = A[i++];
      }
    }
    for (int l = 0; l < k; l++) {
      A[l] = B[l];
    }
  }
}

int main() {
  int n, m, ans = 0;
  scanf("%d%d", &n, &m);
  pt c[n], b[n]; int d[100001];
  for (size_t i = 0; i < n; i++) {
    scanf("%d%d", &(c+i)->day, &(c+i)->money);
  }
  qsort(c, n, sizeof(pt), cmp_day);
  for (int i=0; i<m+1; i++) d[i] = 0;
  for (int i=0; i<n; i++) {
    if (c[i].day > m) break;
    d[c[i].day] = i+1;
  }
  for (int i=1; i<m+1; i++) if (d[i] == 0) d[i] = d[i-1];
  int j=0;
  for (int i=1; i<m+1; i++) {
    if (j>=d[i]) continue;
    if (d[i] != d[i-1]) msort(c+j, b, d[i-1]-j, d[i]-d[i-1]);
    ans += c[j].money;
    j++;
  }
  printf("%d\n", ans);
  return 0;
}
