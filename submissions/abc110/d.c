#include <stdio.h>
#include <math.h>

#define MOD 1000000007

//GCD
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

long c[32][100000];

void combination() {
  for (int i=0; i<100000; i++) c[0][i] = 1;
  for (int i=1; i<32; i++) c[i][0] = 1;
  for (int i=1; i<32; i++) {
    for (int j=1; j<100000; j++) {
      c[i][j] = (c[i-1][j] + c[i][j-1]) % MOD;
    }
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int idx=0, i, p[100000], boo = 0; long ans = 1;
  if (m==1) {
    printf("1\n");
    return 0;
  }
  for (i=2; i<sqrt((double)m); i++) {
    if (m%i != 0) continue;
    boo = 1;
    break;
  }
  if (m%i == 0) boo = 1;
  if (boo) {
    for (i=2; i<=m; i++) {
      if (m%i == 0) {
        p[idx] = 0;
        while (m%i==0) {
          m /= i;
          p[idx]++;
        }
        idx++;
      }
    }
  } else {
    p[idx] = 1;
    idx++;
  }
  combination();
  for (i=0; i<idx; i++) {
    ans = (ans * c[p[i]][n-1]) % MOD;
  }
  printf("%ld\n", ans);
  return 0;
}
