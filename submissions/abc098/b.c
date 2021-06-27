#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  char s[n+1];
  scanf("%s", s);
  int ans = 0;
  for (int i=1; i<n-1; i++) {
    int alph[26] = {0}, cnt = 0;
    for (int j=0; j<i; j++) alph[s[j]-'a']++;
    for (int j=i; j<n; j++) {
      if (alph[s[j]-'a']!=0) {
        cnt++;
        alph[s[j]-'a'] = 0;
      }
    }
    ans = (ans < cnt) ? cnt : ans;
  }
  printf("%d\n", ans);
  return 0;
}
