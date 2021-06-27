#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n, k, r, s, p;
  scanf("%d %d", &n, &k);
  scanf("%d %d %d", &r, &s, &p);
  char t[n+1];
  scanf("%s", t);
  int ans = 0;
  for (int i=0; i<k; i++) {
    if (t[i] == 'r')
      ans += p;
    else if (t[i] == 's')
      ans += r;
    else
      ans += s;
    for (int j = i + k; j < n; j += k)
    {
      if (t[j] == t[j-k]) t[j] = 'o';
      else {
        if (t[j] == 'r')
          ans += p;
        else if (t[j] == 's')
          ans += r;
        else
          ans += s;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
