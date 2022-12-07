#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

//昇順
int acs(const void *a, const void *b)
{
  return *(char *)a - *(char *)b;
}

//降順
int des(const void *a, const void *b)
{
  return *(char *)b - *(char *)a;
}

int main() {
  char s[105], t[105];
  scanf("%s%s", s, t);
  int ls, lt;
  ls = strlen(s);
  lt = strlen(t);
  qsort(s, ls, sizeof(char), acs);
  qsort(t, lt, sizeof(char), des);
  if (strcmp(s, t) < 0)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
