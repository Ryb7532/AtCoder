#include <stdio.h>

int main() {
  int n, k, ans=0, i;
  scanf("%d %d", &n, &k);
  char s[n+2];
  scanf("%s", s+1);
  s[0]='R'; s[n+1]='L';
  for (i=1; i<n+1; i++) {
    if (s[i]=='R') ans = (s[i+1]=='R') ? ans+1 : ans;
    else ans = (s[i-1]=='L') ? ans+1 : ans;
  }
  for (i=1; i<n+1; i++) {
    if (s[i]=='R' && s[i+1]=='L') {
      ans += 2;
      k--;
      if (k==0) break;
    }
  }
  if (i==n+1 || i==n) {
    if (s[1]=='R' && s[n]=='R') ans -= 2;
    else if (s[1]=='L' && s[n]=='R') ans--;
    else if (s[1]=='R' && s[n]=='L') ans--;
  }
  printf("%d\n", ans);
  return 0;
}
