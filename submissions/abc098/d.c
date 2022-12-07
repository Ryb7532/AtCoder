#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  long a[n], sum=0, xor=0, ans=0; int k=0, cnt=0;
  for (int i=0; i<n; i++) scanf("%ld", a+i);
  for (int i=0; i<n; i++) {
    while (k<n && (sum+a[k] == (xor^a[k]))) {
      sum+=a[k];
      xor+=a[k];
      k++;
      cnt++;
    }
    ans+=cnt;
    cnt--;
    sum-=a[i];
    xor-=a[i];
  }
  printf("%ld\n", ans);
  return 0;
}
