#include <stdio.h>
#include <string.h>

int main() {
  char s[4];
  scanf("%s", s);
  int a = 0, b = 0;
  for (int i = 0; i < 2; i++) {
    a = a*10;
    a += (s[i] - '0');
  }
  for (int i = 0; i < 2; i++) {
    b = b*10;
    b += (s[2+i] - '0');
  }
  if (0 < a && a < 13) {
    if (0 < b && b < 13) {
      printf("%s\n", "AMBIGUOUS");
    }else{
      printf("%s\n", "MMYY");
    }
  }else{
    if (0 < b && b < 13) {
      printf("%s\n", "YYMM");
    }else{
      printf("%s\n", "NA");
    }
  }
  return 0;
}
