#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  int s[40], t[40], ans[40], k=0;
  for (int i=0; i<40; i++) {
    s[i] = 0;
    t[i] = 0;
    ans[i] = 0;
  }
  if (n==0) {
    printf("0\n");
    return 0;
  }
  else if (n>0) {
    while (n != 0) {
      s[k] = n%2;
      n /= 2;
      k++;
    }
    for (int i=0; i<k; i++) {
      if (i%2 == 1 && s[i] == 1) {
        s[i] = 0;
        t[i] = 1;
        t[i+1] = 1;
      }
    }
  } else {
    n *= -1;
    while (n != 0) {
      s[k] = n%2;
      n /= 2;
      k++;
    }
    for (int i=0; i<k; i++) {
      if (i%2 == 0 && s[i] == 1) {
        s[i] = 0;
        t[i] = 1;
        t[i+1] = 1;
      }
    }
  }
  for (int i=0; i<40; i++) {
    if (s[i] == 1 && t[i] == 1) {
      if (t[i+1] == 1) {
        t[i+1] = 0;
        ans[i] = 0;
      } else {
        t[i+1] = 1;
        t[i+2] = 1;
        ans[i] = 0;
      }
    } else if (s[i] == 0 && t[i] == 0) {
      ans[i] = 0;
    } else {
      ans[i] = 1;
    }
  }
  k=39;
  while (ans[k]==0) k--;
  for (; k>=0; k--) printf("%d", ans[k]);
  printf("\n");
  return 0;
}
