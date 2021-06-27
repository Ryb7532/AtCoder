#include <stdio.h>

int main() {
  int p, q, r, s, ans;
  scanf("%d %d %d", &p, &q, &r);
  s = (p>q) ? p : q;
  s = (s>r) ? s : r;
  ans = p+q+r-s;
  printf("%d\n", ans);
  return 0;
}
