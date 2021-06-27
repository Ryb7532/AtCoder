#include <stdio.h>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  if(a%2==1 && b%2 == 1) {
    printf("Yes\n");
    return 0;
  }
  printf("No\n");
  return 0;
}
