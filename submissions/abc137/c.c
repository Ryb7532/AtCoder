#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *str;

int cmp_char(const void *x, const void *y) {
  return *(char *)x-*(char *)y;
}

int cmp_str(const void *x, const void *y) {
  return strcmp((str)x, (str)y);
}

int main() {
  int n; long long int ans = 0;
  scanf("%d\n", &n);
  char s[n][20];
  for (size_t i = 0; i < n; i++) {
    gets(s[i]);
    qsort(s[i], 10, sizeof(char), cmp_char);
  }
  qsort(s, n, sizeof(char)*20, cmp_str);
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (strcmp(s[i], s[i-1]) == 0) {
      cnt++;
      ans += cnt;
    }else {
      cnt = 0;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
