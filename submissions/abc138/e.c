#include <stdio.h>
#include <string.h>

int main() {
  char s[100001], t[100001];
  scanf("%s %s", s, t);
  int ls = strlen(s), lt = strlen(t), substr[ls+1][26]; long ans = 0;
  for (int i=0; i<26; i++) substr[ls][i] = -1;
  for (int i=ls-1; i>=0; i--) {
    for (int j=0; j<26; j++) substr[i][j] = substr[i+1][j];
    substr[i][s[i]-'a'] = i;
  }
  int idx = 0;
  for (int i=0; i<lt; i++) {
    int numt = t[i]-'a';
    if (substr[0][numt] == -1) {
      printf("-1\n");
      return 0;
    }
    if (substr[idx][numt] == -1) {
      ans += ls-idx;
      idx = 0;
    }
    ans += substr[idx][numt]+1 - idx;
    idx = substr[idx][numt]+1;
  }
  printf("%ld\n", ans);
  return 0;
}
