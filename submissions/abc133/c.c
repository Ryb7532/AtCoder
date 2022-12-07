#include <stdio.h>
#include <limits.h>

int main() {
  int l, r, ans = INT_MAX;
  scanf("%d %d", &l, &r);
  int mod;
  if (r-l >= 2019) ans = 0;
  else{
    l = l%2019; r = r%2019;
    if (r<l) {
      ans = 0;
    }else {
      for (size_t i = l; i < r; i++) {
        for (size_t j = l+1; j <= r; j++) {
          mod = (i*j)%2019;
          ans = (ans > mod) ? mod : ans;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
