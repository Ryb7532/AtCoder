#include <stdio.h>

#define MAX(a, b) ((a>b)?a:b)
#define MAX3(a, b, c) MAX(MAX(a, b), c)

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  printf("%d\n", MAX3(a, b, c)*9+a+b+c);
  return 0;
}
