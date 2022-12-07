#include <stdio.h>
#include <string.h>

int main() {
  char s[200001], t[200001];
  scanf("%s %s", s, t);
  int l = strlen(s), a[26], b[26];
  for (int i=0; i<26; i++) {
    a[i] = -1;
    b[i] = -1;
  }
  for (int i=0; i<l; i++) {
    int cs = s[i]-'a';
    int ct = t[i]-'a';
    if (a[cs] == -1 && b[ct] == -1) {
      a[cs] = ct;
      b[ct]++;
    } else if (a[cs] != -1 && ct == a[cs]) continue;
    else {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}
