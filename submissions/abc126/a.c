#include <stdio.h>

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  char s[n];
  scanf("%s", s);
  if (s[k-1] == 'A') {
    s[k-1] = 'a';
  }
  else if (s[k-1] == 'B') {
    s[k-1] = 'b';
  }else{
    s[k-1] = 'c';
  }
  printf("%s\n", s);
  return 0;
}
