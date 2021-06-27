#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  char t[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  char s[4];
  scanf("%s", s);
  for (int i=0; i<7; i++) {
    if (strcmp(t[i], s) == 0) {
      printf("%d\n", 7-i);
    }
  }
  return 0;
}
