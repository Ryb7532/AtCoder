#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
  int n, a, b, c;
  scanf("%d%d%d%d", &n, &a, &b, &c);
  int l[n], m = (1<<(2*n)), ah, bh, ch, p[m], ans = INT_MAX;
  for (int i=0; i<n; i++) scanf("%d", l+i);
  for (int i=0; i<m; i++) p[i] = 0;
  for (int i=0; i<m; i++) {
    ah = 0; bh = 0; ch = 0;
    for (int j=0; j<n; j++) {
      int k = (3 & (i>>(2*j)));
      if (k == 1) {
        if (ah != 0) p[i] += 10;
        ah += l[j];
      } else if (k == 2) {
        if (bh != 0) p[i] += 10;
        bh += l[j];
      } else if (k == 3) {
        if (ch != 0) p[i] += 10;
        ch += l[j];
      }
    }
    if (ah == 0 || bh == 0 || ch == 0) {
      p[i] = INT_MAX;
      continue;
    }
    p[i] += abs(ah - a) + abs(bh - b) + abs(ch - c);
    ans = (ans > p[i]) ? p[i] : ans;
  }
  printf("%d\n", ans);
  return 0;
}
