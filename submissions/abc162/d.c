#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  char s[n+5];
  scanf("%s", s);
  int cnt[3][n+1];
  cnt[0][n] = 0;
  cnt[1][n] = 0;
  cnt[2][n] = 0;
  for (int i=n-1; i>=0; i--) {
    cnt[0][i] = cnt[0][i+1] + (s[i] == 'R');
    cnt[1][i] = cnt[1][i+1] + (s[i] == 'G');
    cnt[2][i] = cnt[2][i+1] + (s[i] == 'B');
  }
  long ans = 0;
  for (int i=0; i<n-2; i++) {
    for (int j=i+1; j<n-1; j++) {
      if (s[i] == 'R') {
        if (s[j] == 'G') {
          ans += cnt[2][j+1];
          if (2*j-i < n && s[2*j-i] == 'B')
            ans--;
        } else if (s[j] == 'B') {
          ans += cnt[1][j+1];
          if (2*j-i < n && s[2*j-i] == 'G')
            ans--;
        }
      } else if (s[i] == 'G') {
        if (s[j] == 'B') {
          ans += cnt[0][j+1];
          if (2*j-i < n && s[2*j-i] == 'R')
            ans--;
        } else if (s[j] == 'R') {
          ans += cnt[2][j+1];
          if (2*j-i < n && s[2*j-i] == 'B')
            ans--;
        }
      } else {
        if (s[j] == 'R') {
          ans += cnt[1][j+1];
          if (2*j-i < n && s[2*j-i] == 'G')
            ans--;
        } else if (s[j] == 'G') {
          ans += cnt[0][j+1];
          if (2*j-i < n && s[2*j-i] == 'R')
            ans--;
        }
      }
    }
  }
  printf("%ld\n", ans);
  return 0;
}
