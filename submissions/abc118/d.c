#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct num{
  int number;
  int count;
};

int cmp(const void* a, const void* b) {
  return (*(struct num*)b).number - (*(struct num*)a).number;
}

int main() {
  int b[9] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
  int n, m, t, i, j, max;
  scanf("%d%d", &n, &m);
  struct num num[m];
  int dp[n+1];
  for (i = 0; i < m; i++) {
    scanf("%d", &t);
    num[i].number = t;
    num[i].count = b[t-1];
  }
  qsort(num, m, sizeof(struct num), cmp);
  dp[0] = 0;
  for (i = 1; i < n+1; i++) {
    max = INT_MIN;
    for (j = 0; j < m; j++) {
      if (i-num[j].count >= 0) {
        max = (max < dp[i-num[j].count]+1) ? dp[i-num[j].count]+1 : max;
      }
    }
    dp[i] = max;
  }
  while (n > 0) {
    i = 0;
    while (n-num[i].count < 0 || dp[n-num[i].count] != dp[n] -1) {
      i++;
    }
    n -= num[i].count;
    printf("%d", num[i].number);
  }
  printf("\n");
  return 0;
}
