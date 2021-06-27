#include <stdio.h>

typedef struct Prime {
  int p;
  int cnt;
} P;

//GCD
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  int n;
  scanf("%d", &n);
  P p[50]; int c=0, m;
  for (int i=2; i<=n; i++) {
    m=i;
    for (int j=0; j<c; j++) {
      if (gcd(m, p[j].p) != 1) {
        while (m % p[j].p == 0) {
          m = m / p[j].p;
          p[j].cnt++;
        }
      }
    }
    if (m != 1) {
      p[c].p = m;
      p[c].cnt = 1;
      c++;
    }
  }
  int ce74 = 0, ce24 = 0, ce14 = 0, ce4 = 0, ce2 = 0;
  for (int i=0; i<c; i++) {
    if (p[i].cnt >= 2) ce2++;
    if (p[i].cnt >= 4) ce4++;
    if (p[i].cnt >= 14) ce14++;
    if (p[i].cnt >= 24) ce24++;
    if (p[i].cnt >= 74) ce74++;
  }
  int ans = 0;
  ans += (ce74 >= 1) ? ce74 : 0;
  ans += (ce24 >= 1) ? ce24*(ce2-1) : 0;
  ans += (ce14 >= 1) ? ce14*(ce4-1) : 0;
  ans += (ce4 >= 2) ? ce4*(ce4-1)*(ce2-2)/2 : 0;
  printf("%d\n", ans);
  return 0;
}
