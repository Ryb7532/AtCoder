#include <stdio.h>

int main() {
  int a; char s[15];
  scanf("%d\n", &a);
  gets(s);
  if (a < 3200) {
    printf("red\n");
  }else {
    printf("%s\n", s);
  }
  return 0;
}
