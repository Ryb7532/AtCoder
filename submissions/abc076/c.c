#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  char s[55], t[55];
  scanf("%s%s", s, t);
  int n = strlen(s), m = strlen(t);
  for (int i=n-m; i>=0; i--) {
    bool check = true;
    for (int j=0; j<m; j++) {
      if (s[i+j] == '?' || s[i+j] == t[j])
        continue;
      else {
        check = false;
        break;
      }
    }
    if (check) {
      for (int j=0; j<m; j++)
        s[i+j] = t[j];
      for (int j=0; j<n; j++)
        if (s[j] == '?')
          s[j] = 'a';
      printf("%s\n", s);
      return 0;
    }
  }
  printf("UNRESTORABLE\n");
  return 0;
}
