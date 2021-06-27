#include <stdio.h>
//WA
int main() {
  long int a, b, ans = 0, s;
  scanf("%ld%ld", &a, &b);
  if (a%2) {
    s = b-a;
    if (s%2) {
      ans = a ^ b ^ ((s/2)%2);
    } else {
      ans = a ^ ((s/2)%2);
    }
  } else {
    s = b-a+1;
    if (s%2) {
      ans = b ^ ((s/2)%2);
    } else {
      ans = ((s/2)%2);
    }
  }
  printf("%ld\n", ans);
  return 0;
}
