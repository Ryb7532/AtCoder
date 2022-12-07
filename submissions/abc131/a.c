#include <stdio.h>

int main() {
  char s[4];
  scanf("%s", s);
  for (size_t i = 0; i < 3; i++) {
    if (s[i] == s[i+1]) {
      printf("Bad\n");
      return 0;
    }
  }
  printf("Good\n");
  return 0;
}
