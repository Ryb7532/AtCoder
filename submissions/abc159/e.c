#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
#include <limits.h>
//#include <math.h>

#define Min(a, b) ((a < b) ? a : b)

int main() {
  int h, w, k;
  scanf("%d%d%d", &h, &w, &k);
  char s[h][w+5];
  for (int i=0; i<h; i++)
    scanf("%s", s[i]);
  int cnt[h+1][w+1], ans = INT_MAX;
  for (int i=0; i<w+1; i++)
    cnt[0][i] = 0;
  for (int i=0; i<h+1; i++)
    cnt[i][0] = 0;
  for (int i=0; i<h; i++)
    for (int j=0; j<w; j++)
      cnt[i+1][j+1] = cnt[i][j+1]+cnt[i+1][j]-cnt[i][j]+(s[i][j]=='1');
  for (int i=(1<<(h-1)); i<(1<<h); i++) {
    int c, d = 0, a = 0, tmpi = i;
    bool check = true;
    while (tmpi != 1) {
      a += tmpi%2;
      tmpi /= 2;
    }
    for (int j=0; j<w; j++) {
      c = 0;
      for (int l=0; l<h; l++) {
        if (i & (1<<l)) {
          if (cnt[l+1][j+1] - cnt[c][j+1] - cnt[l+1][d]+cnt[c][d] > k) {
            if (cnt[l+1][j+1]-cnt[l+1][j]-cnt[c][j]+cnt[c][j] > k) {
              check = false;
              break;
            }
            a++;
            d = j;
          }
          c = l+1;
        }
      }
      if (!check)
        break;
    }
    if (!check)
      continue;
    ans = Min(ans, a);
  }
  if (ans == INT_MAX)
    ans = 0;
  printf("%d\n", ans);
  return 0;
}
