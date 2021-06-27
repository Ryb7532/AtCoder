#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <math.h>

int main() {
  char s[101];
  long n;
  scanf("%s %ld", s, &n);
  int i=0;
  while (s[i] == '1' && i<n-1) i++;
  printf("%c\n", s[i]);
  return 0;
}
