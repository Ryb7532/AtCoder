#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int k;
  scanf("%d", &k);
  long r[100001] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int id = 0;
  for (int i=9; i<k; i++) {
    if (r[id] % 10 == 0) {
      r[i] = r[id] * 10;
      r[i+1] = r[i] + 1;
    } else if (r[id] % 10 == 9) {
      r[i] = r[id] * 10 + 8;
      r[i+1] = r[i] + 1;
    } else {
      r[i] = r[id] * 10 + r[id]%10 - 1;
      r[i+1] = r[i] + 1;
      i++;
      r[i+1] = r[i] + 1;
    }
    i++;
    id++;
  }
  printf("%ld\n", r[k-1]);
  return 0;
}
