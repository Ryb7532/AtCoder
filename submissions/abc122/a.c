#include <stdio.h>

int main() {
  char base, ans;
  scanf("%c", &base);
  if (base == 'A') {
    ans = 'T';
  } else if (base == 'C') {
    ans = 'G';
  } else if (base == 'T') {
    ans = 'A';
  } else {
    ans = 'C';
  }
  printf("%c\n", ans);
  return 0;
}
