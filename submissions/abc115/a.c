#include <stdio.h>
#include <string.h>

int main() {
  char ans[4][50] = {
    "Christmas",
    "Christmas Eve",
    "Christmas Eve Eve",
    "Christmas Eve Eve Eve"};
  int d;
  scanf("%d", &d);
  printf("%s\n", ans[25-d]);
  return 0;
}
