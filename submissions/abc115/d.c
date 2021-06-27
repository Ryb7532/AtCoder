#include <stdio.h>

long int  count(int n, long int k) {
  if (n < 0 || k <= 0) {
    return 0;
  }
  if (k*2 > (1ull<<(n+2))-3) {
    return (1ull<<n) + count(n-1, k-(1ull<<(n+1))+1);
  } else {
    return count(n-1, k-1);
  }
}

int main() {
  int n;
  long int x;
  scanf("%d%ld", &n, &x);
  long int cnt;
  cnt = count(n, x);
  printf("%ld\n", cnt);
  return 0;
}
