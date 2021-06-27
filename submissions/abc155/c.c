#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

typedef struct StrCnt{
  char *s;
  int cnt;
} Str;

//昇順
int des_acs(const void *a, const void *b)
{
  if (((Str *)a)->cnt == ((Str *)b)->cnt)
    return strcmp((((Str *)a)->s), (((Str *)b)->s));
  else
    return ((Str *)b)->cnt - ((Str *)a)->cnt;
}

//降順
int des(const void *a, const void *b)
{
  return strcmp((char *)b, (char *)a);
}

int main() {
  int n;
  scanf("%d\n", &n);
  char s[n][15];
  for (int i=0; i<n; i++)
    scanf("%s", s[i]);
  qsort(s, n, sizeof(char)*15, des);
  //for (int i=0; i<n; i++) printf("%s\n", s[i]);
  Str cnt[n];
  cnt[0].s = s[0];
  cnt[0].cnt = 1;
  int j = 0;
  for (int i=1; i<n; i++) {
    if (strcmp(s[i], cnt[j].s)) {
      j++;
      cnt[j].s = s[i];
      cnt[j].cnt = 1;
    } else {
      cnt[j].cnt++;
    }
  }
  j++;
  qsort(cnt, j, sizeof(Str), des_acs);
  int max = cnt[0].cnt, k = 0;
  while (cnt[k].cnt == max && k<j) {
    printf("%s\n", cnt[k].s);
    k++;
  }
  return 0;
}
