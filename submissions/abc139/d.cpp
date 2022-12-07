#include <stdio.h>
#include <limits.h>
int main() {
  long int n;
  scanf("%ld", &n);
  printf("%ld\n", (n*(n-1))/2);
  return 0;
}
