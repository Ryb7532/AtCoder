#include <stdio.h>
#include <string.h>

int main() {
  int n, ans = 0;
  scanf("%d\n", &n);
  char s[5005]; int a[n][n];
  scanf("%s", s);
  for (int i=0; i<n; i++) {
    a[i][i] = n-i;
  }
  for (int i=0; i<n; i++) {
    int j = i+1, k = 0;
    while (j<n) {
      while (j+k<n && s[i+k]==s[j+k]) k++;
      a[i][j] = k;
      if (k==0) {
        j++;
        continue;
      }
      int l = 1;
      while (j+l<n && l+a[i][l+i]<k) {
        a[i][j+l] = a[i][i+l];
        l++;
      }
      j+=l;
      k-=l;
    }
  }
  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      if (a[i][j]>j-i) a[i][j] = j-i;
      ans = (ans < a[i][j]) ? a[i][j] : ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
