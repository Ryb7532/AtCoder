#include <stdio.h>

int main() {
  double w, h, x, y;
  scanf("%lf %lf %lf %lf", &w, &h, &x, &y);
  double s = (w * h) / 2.00;
  int boo;
  boo = (x != w/2.00) ? 0 :
        (y != h/2.00) ? 0 : 1;
  printf("%lf %d\n", s, boo);
  return 0;
}
