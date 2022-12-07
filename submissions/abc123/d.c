#include <stdio.h>
#include <stdlib.h>
//TLE
/*int compare_int(const void *a, const void *b) {
  int c = *(int*)a;
  int d = *(int*)b;
  if (c & (1<<31)) {
    if (d & (1<<31)) {
      return d-c;
    } else {
      return -1;
    }
  } else {
    if (d & (1<<31)) {
      return 1;
    } else {
      return d-c;
    }
  }
}*/
int compare_long(const void *a, const void *b) {
  if (*(long int*)b - *(long int*)a > 0) {
    return 1;
  } else {
    return -1;
  }
}
int main() {
  int x, y, z, l;
  scanf("%d %d %d %d", &x, &y, &z, &l);
  long int a[x], b[y], c[z];
  for (int i = 0; i < x; i++) {
    scanf("%ld", a+i);
  }
  for (int i = 0; i < y; i++) {
    scanf("%ld", b+i);
  }
  for (int i = 0; i < z; i++) {
    scanf("%ld", c+i);
  }

  qsort(a, x, sizeof(long int), compare_long);
  /*for (int i = 0; i < x; i++) {
    printf("%ld\n", *(a+i));
  }*/
  qsort(b, y, sizeof(long int), compare_long);
  qsort(c, z, sizeof(long int), compare_long);
  if (x>l) x = l;
  if (y>l) y = l;
  if (z>l) z = l;
  int w = x*y;
  if (w>l) w = l;
  long int p[x*y], q[w*z];
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      p[y*i + j] = a[i] + b[j];
    }
  }
  qsort(p, x*y, sizeof(long int), compare_long);
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < z; j++) {
      q[z*i + j] = p[i] + c[j];
    }
  }
  qsort(q, w*z, sizeof(long int), compare_long);
  for (int i = 0; i < l; i++) {
    printf("%ld\n", q[i]);
  }
  return 0;
}
