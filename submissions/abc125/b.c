#include <stdio.h>

int main() {
  int n, ans = 0;
  scanf("%d", &n);
  int V[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", V+i);
  }
  for (int i = 0; i < n; i++) {
    int s;
    scanf("%d", &s);
    s = V[i] - s;
    if(s > 0){
      ans += s;
    }
  }
  printf("%d\n", ans);
  return 0;
}
