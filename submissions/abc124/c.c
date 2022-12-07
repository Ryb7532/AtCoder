#include <stdio.h>

int main() {
  char s[100000];
  scanf("%s", s);
  int size = 0;
  do {
    size++;
  } while(*(s+size) != '\0');
  char zero = '0', one = '1';
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (((i%2 == 1) && (*(s+i) == zero)) || ((i%2 == 0) && (*(s+i) == one))) {
      count++;
    }
  }
  if (count > size - count) {
    count = size - count;
  }
  printf("%d\n", count);
  return 0;
}
