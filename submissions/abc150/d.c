#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

long gcd(long a, long b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

long lcm(long a, long b) {
  long g = gcd(a, b);
  return a*b/g;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  long a[n];
  scanf("%ld", a);
  long b = a[0], l = b/2;
  int cnt = 0;
  while (b%2 == 0) {
    cnt++;
    b /= 2;
  }
  for (int i=1; i<n; i++) {
    scanf("%ld", a+i);
    int cnti = 0;
    b = a[i];
    while (b%2 == 0) {
      cnti++;
      b /= 2;
    }
    if (cnt != cnti) {
      printf("0\n");
      return 0;
    }
    l = lcm(a[i]/2, l);
  }
  printf("%ld\n", m/l-m/(2*l));
  return 0;
}
