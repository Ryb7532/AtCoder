#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  int s[999]; s[0] = 1;
  for (int i=1; i<999; i++) s[i] = s[i-1] + i+1;
  printf("%d\n", s[b-a-1] - b);
  return 0;
}
