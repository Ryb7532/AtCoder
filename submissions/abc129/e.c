#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
//#include <limits.h>
//#include <math.h>

#define MOD 1000000007

int main() {
  char l[1000002];
  scanf("%s", l);
  int n=strlen(l);
  long dp1[n], dp2[n];
  dp1[0] = 1; dp2[0] = 2;
  for (int i=1; i<n; i++) {
    if (l[i] == '0') {
      dp1[i] = dp1[i-1]*3;
      dp1[i] %= MOD;
      dp2[i] = dp2[i-1];
    } else {
      dp1[i] = dp1[i-1]*3+dp2[i-1];
      dp1[i] %= MOD;
      dp2[i] = dp2[i-1]*2;
      dp2[i] %= MOD;
    }
  }
  long ans = (dp1[n-1] + dp2[n-1]) % MOD;
  printf("%ld\n", ans);
  return 0;
}
