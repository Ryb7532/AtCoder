#include <stdio.h>
#include <string.h>

int main() {
  char s[11], t[11] = "2019/04/30";
  scanf("%s", s);
  if (strcmp(s, t) <= 0) {
    printf("Heisei\n");
  } else {
    printf("TBD\n");
  }
  return 0;
}
