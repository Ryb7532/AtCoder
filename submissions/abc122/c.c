#include <stdio.h>
//WA
struct lr {
  int r;
  int l;
};

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  char s[n+1];
  struct lr a[q];
  scanf("%s", s);
  for (size_t i = 0; i < q; i++) {
    scanf("%d%d", &a[i].l, &a[i].r);
  }
  int b[n+1], boo = 0;
  b[0] = 0;
  for (size_t i = 1; i <= n; i++) {
    if (s[i-1] == 'A') {
      boo = 1;
      b[i] = b[i-1];
    } else if (boo == 1 && s[i-1] == 'C') {
      boo = 0;
      b[i] = b[i-1] + 1;
    } else {
      boo = 0;
      b[i] = b[i-1];
    }
  }
  for (size_t i = 0; i < q; i++) {
    int ans = b[a[i].r] - b[a[i].l];
    printf("%d\n", ans);
  }
  /*TLE
  for (size_t i = 0; i < q; i++) {
    int count = 0, boo = 0;
    for (size_t j = (a[i].l)-1; j < a[i].r; j++) {
      if (s[j] == 'A') {
        boo = 1;
      } else if (boo == 1 && s[j] == 'C') {
        count++;
        boo = 0;
      } else {
        boo = 0;
      }
    }
    printf("%d\n", count);
  }*/
  return 0;
}
