#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <limits.h>
//#include <math.h>

//昇順
int acs(const void *a, const void *b) {
  return strcmp((char *)a, (char *)b);
}

int main() {
  char s[5001];
  scanf("%s", s);
  int k, l=strlen(s);
  scanf("%d", &k);
  char sub[k*l][6]; int idx = 0;
  for (int i=0; i<l; i++) {
    for (int j=0; j<k && j+i<l; j++) {
      for (int m=0; m<j+1; m++) {
        sub[idx][m] = s[i+m];
        sub[idx][m+1] = '\0';
      }
      idx++;
    }
  }
  qsort(sub, idx, sizeof(char)*6, acs);
  int i=1;
  for (int cnt=1; cnt<k; i++) {
    if (strcmp(sub[i-1], sub[i])==0) continue;
    cnt++;
  }
  printf("%s\n", sub[i-1]);
  return 0;
}
