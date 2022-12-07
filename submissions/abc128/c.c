#include <stdio.h>

int count(int a) {
  int cnt;
  cnt = (a & 0x5555) + ((a>>1) & 0x5555);
  cnt = (cnt & 0x3333) + ((cnt >> 2) & 0x3333);
  cnt = (cnt & 0x0f0f) + ((cnt >> 4) & 0x0f0f);
  return (cnt & 0x00ff) + ((cnt >> 8) & 0x00ff);
}

int main() {
  int n, m, ans = 0, k, l, boo;
  scanf("%d %d", &n, &m);
  int s[m], p[m];
  for (size_t i = 0; i < m; i++) {
    scanf("%d", &k);
    s[i] = 0;
    for (size_t j = 0; j < k; j++) {
      scanf("%d", &l);
      s[i] += (1<<(l-1));
    }
  }
  for (size_t i = 0; i < m; i++) {
    scanf("%d", p+i);
  }
  for (size_t i = 0; i < (1<<n); i++) {
    boo = 1;
    for (size_t j = 0; j < m; j++) {
      if(count(s[j] & i) % 2 != p[j]){
        boo = 0;
        break;
      }
    }
    if (boo == 1) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
