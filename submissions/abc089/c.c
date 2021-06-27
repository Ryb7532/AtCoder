#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  char s[n][11];
  long cnt[5] = {0}, ans = 0;
  for (int i=0; i<n; i++) {
    scanf("%s", s[i]);
    if (s[i][0] == 'M') cnt[0]++;
    if (s[i][0] == 'A') cnt[1]++;
    if (s[i][0] == 'R') cnt[2]++;
    if (s[i][0] == 'C') cnt[3]++;
    if (s[i][0] == 'H') cnt[4]++;
  }
  for (int i=0; i<3; i++) {
    for (int j=i+1; j<4; j++) {
      for (int k=j+1; k<5; k++) {
        ans += cnt[i] * cnt[j] * cnt[k];
      }
    }
  }
  printf("%ld\n", ans);
  return 0;
}
