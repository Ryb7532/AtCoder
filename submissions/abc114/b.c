#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
  char s[10];
  gets(s);
  int a[10], i = 0, min = INT_MAX;
  while(s[i] != '\0') {
    a[i] = s[i] - '0';
    i++;
  }
  for (size_t j = 0; j < i-2; j++) {
    int b = a[j+2] + (a[j+1] * 10) + (a[j] * 100);
    b = abs(b - 753);
    min = (b < min) ? b : min;
  }
  printf("%d\n", min);
  return 0;
}
