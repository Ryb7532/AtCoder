#include <stdio.h>

int main() {
  char s[10];
  scanf("%s", s);
  int i = 0, max = 0, count = 0;
  while (s[i] != '\0') {
    if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
      count++;
    } else {
      count = 0;
    }
    if (max < count) {
      max = count;
    }
    i++;
  }
  printf("%d\n", max);
  return 0;
}
