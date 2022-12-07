#include <stdio.h>
#include <limits.h>


#define MIN(a, b) ((a<b)?a:b)

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a[m], b, c[m], tmp, ans;
  for (int i=0; i<m; i++) {
    scanf("%d%d", a+i, &b);
    c[i]=0;
    for (int j=0; j<b; j++) {
      scanf("%d", &tmp);
      c[i]+=(1<<(tmp-1));
    }
  }
  int dp[m][(1<<n)];
  dp[0][0]=0;
  for (int i=1; i<(1<<n); i++) {
    if ((c[0]&i)!=i) dp[0][i] = INT_MAX;
    else dp[0][i] = a[0];
  }
  for (int i=1; i<m; i++) {
    for (int j=1; j<(1<<n); j++) {
      if (dp[i-1][j-(c[i]&j)]==INT_MAX) dp[i][j] = dp[i-1][j];
      else dp[i][j] = MIN(dp[i-1][j], dp[i-1][j-(c[i]&j)]+a[i]);
    }
  }
  ans = (dp[m-1][(1<<n)-1]==INT_MAX) ? -1 : dp[m-1][(1<<n)-1];
  printf("%d\n", ans);
  return 0;
}
