#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
#include <limits.h>
//#include <math.h>

int main() {
  int n, k, c;
  scanf("%d%d%d", &n, &k, &c);
  char s[n+5];
  scanf("%s", s);
  int cnt[n+1], j = INT_MAX;
  cnt[n] = 0;
  for (int i=n-1; i>=0; i--) {
    if (s[i] == 'x' || j - i < c + 1)
      cnt[i] = cnt[i+1];
    else {
      cnt[i] = cnt[i+1] + 1;
      j = i;
    }
  }
  //for (int i=0; i<n; i++) printf("%d ", cnt[i]);
  int ans[k+1];
  ans[0] = INT_MIN;
  j = 0;
  for (int i=0; i<n && j<=k; i++) {
    if (s[i] == 'o' && ans[j] + c < i) {
      j++;
      ans[j] = i;
    }
  }
  //for (int i=1; i<=k; i++) printf("%d ", ans[i]);
  for (int i=0; i<k; i++) {
    if (cnt[ans[i+1]] == cnt[ans[i+1]+1]+1 && cnt[ans[i+1]] == k - i)
      printf("%d\n", ans[i+1]+1);
  }
  return 0;
}
