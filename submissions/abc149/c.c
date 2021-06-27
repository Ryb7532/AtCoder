#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <limits.h>
#include <math.h>

bool primeCheck(int m)
{
  bool b = true;
  int i;
  if (m == 1) return false;
  if (m == 2) return true;
  for (i = 2; i < sqrt((double)m); i++)
  {
    if (m % i != 0)
      continue;
    b = false;
    break;
  }
  if (m % i == 0)
    b = false;
  return b;
}

int main() {
  int x;
  scanf("%d", &x);
  while (!primeCheck(x)) x++;
  printf("%d\n", x);
  return 0;
}
