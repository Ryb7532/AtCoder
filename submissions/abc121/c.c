#include <stdio.h>
#include <stdlib.h>

struct drink {
  int cost;
  int num;
};

int asc(const void *a, const void *b) {
  return (*(struct drink*)a).cost - (*(struct drink*)b).cost;
}

int main() {
  int n, m, i = 0, count = 0, ncount = 0;
  long int price = 0;
  scanf("%d%d", &n, &m);
  struct drink st[n];
  for (size_t i = 0; i < n; i++) {
    scanf("%d%d", &(st[i].cost), &(st[i].num));
  }
  qsort(st, n, sizeof(struct drink), asc);
  while (count < m) {
    price += st[i].cost;
    if (ncount+1 >= st[i].num) {
      i++;
      ncount = 0;
    } else {
      ncount++;
    }
    count++;
  }
  printf("%ld\n", price);
  return 0;
}
