#include <stdio.h>

#define N 1000000007;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  long int c[2001][2001], ans;
  c[0][0] = 1;
  for (size_t i = 1; i < 2001; i++) {
    c[i][0] = 1; c[i][i] = 1;
    for (size_t j = 1; j < i; j++) {
      c[i][j] = (c[i-1][j] + c[i-1][j-1])%N;
    }
  }
  for (size_t i = 1; i < k+1; i++) {
    if (n-k+1<i) {
      ans = 0;
    }else {
      ans = (c[k-1][i-1] * c[n-k+1][i])%N;
    }
    printf("%ld\n", ans);
  }
  return 0;
}
