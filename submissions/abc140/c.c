#include <stdio.h>
#include <limits.h>

#define MIN(a, b) ((a) > (b) ? (b) : (a))

int main() {
  int n;
  scanf("%d\n", &n);
  int b[n-1];
  for (int i=0; i<n-1; i++) {
    scanf("%d", b+i);
  }
  int sum = b[0];
  for (int i=0; i<n-2; i++) {
    sum += MIN(b[i+1], b[i]);
  }
  printf("%d\n", sum+b[n-2]);
  return 0;
}
