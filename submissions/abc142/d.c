#include <stdio.h>
#include <math.h>

long int gcd(long int x, long int y) {
  if(x <= 0) return y;
  return gcd(y%x, x);
}

int main() {
  long int a, b;
  scanf("%ld%ld", &a, &b);
  long int g = gcd(a, b);
  int ans = 1;
  /*for (int i=1; i<=sqrt((double)g); i++) {
    if(g%i!=0) continue;
    int boo=1;
    for (int j=2; j<=sqrt((double)i); j++) {
      if(i%j!=0) continue;
      boo = 0;
      break;
    }
    if(boo) ans++;

    int l=g/i;
    if (l==i) continue;
    boo=1;
    for (int j=2; j<=sqrt((double)l); j++) {
      if(l%j!=0) continue;
      boo = 0;
      break;
    }
    if(boo) ans++;
  }*/
  for (int i=2; i<=sqrt((double)g); i++) {
    if (g%i!=0) continue;
    ans++;
    while (g%i==0) g/=i;
  }
  if(g>1) ans++;
  printf("%d\n", ans);
  return 0;
}
