#include <stdio.h>

int main() {
  char s[10];
  char sun[10] = {'S', 'u', 'n', 'n', 'y'},
       clo[10] = {'C', 'l', 'o', 'u', 'd', 'y'},
       rain[10] = {'R', 'a', 'i', 'n', 'y'};
  scanf("%s", s);
  if (s[0] == sun[0]) {
    printf("Cloudy\n");
  }else if (s[0] == clo[0]) {
    printf("Rainy\n");
  }else {
  printf("Sunny\n");
  }
  return 0;
}
