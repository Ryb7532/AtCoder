#include <stdio.h>
#include <stdlib.h>

//昇順
int acs(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int min = (n<k) ? n : k;
  int v[n], ab[min+1][min+1], have[min+1][min+1][min];
  for (int i=0; i<n; i++) scanf("%d", v+i);
  ab[0][0] = 0;
  for (int i=1; i<min+1; i++) {
    ab[i][0] = ab[i-1][0] + v[i-1];
    for (int j=0; j<i; j++) {
      have[i][0][j] = v[j];
    }
  }
  for (int i=0; i<min+1; i++) {
    for (int j=1; j<min+1-i; j++) {
      ab[i][j] = ab[i][j-1] + v[n-j];
      for (int k=0; k<i; k++) have[i][j][k] = v[k];
      for (int k=0; k<j; k++) have[i][j][i+k] = v[n-k-1];
    }
  }
  for (int i=0; i<min+1; i++) {
    for (int j=0; j<min+1-i; j++) {
      if (i+j == k) continue;
      int c=0;
      qsort(have[i][j], i+j, sizeof(int), acs);
      while(c<k - (i+j) && have[i][j][c]<0 && c<i+j) {
        ab[i][j] += -have[i][j][c];
        c++;
      }
    }
  }
  int ans=0;
  for (int i=0; i<min+1; i++) {
    for (int j=0; j<min+1-i; j++) {
      ans = (ab[i][j]>ans) ? ab[i][j] : ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
