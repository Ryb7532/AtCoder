#include <stdio.h>

void sort(int a[], int n){
  int b, i, j = 0, k = 1;//0~j-1 small j~k-1 equal k~i-1 big i~ unsorted
  b = a[0];
  if(n <= 1) return;
  for (i = 1; i < n; i++) {
    if(a[i] < b){
      a[j] = a[i];
      a[i] = a[k];
      a[k] = b;
      j++;
      k++;
    }else if(a[i] == b){
      a[i] = a[k];
      a[k] = b;
      k++;
    }
  }
  sort(a, j);
  sort(a+k, n-k);
  return;
}

void main() {
  int n, ans = 0;
  scanf("%d", &n);
  int a[n*2];
  for (int i = 0; i < n*2; i++) {
    scanf("%d", a+i);
  }
  sort(a, n*2);
  for (int i = 0; i < n; i++) {
    ans += a[i*2];
  }
  printf("%d\n", ans);
  return;
}
