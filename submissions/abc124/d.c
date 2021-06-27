#include <stdio.h>
//mistake
struct st{
  char a;
  int b;
};

int min(int a, int b) {
  if (a < b) return a;
  else return b;
}

int main() {
  int n, k;
  scanf("%d %d\n", &n, &k);
  struct st st[n];
  char s, t;
  scanf("%c", &s);
  t = s;
  st[0].a = s;
  st[0].b = 1;
  int j = 0;
  for (int i = 1; i < n; i++) {
    scanf("%c", &s);
    if (s == t) {
      st[j].b += 1;
    } else {
      j++;
      st[j].a = s;
      st[j].b = 1;
      t = s;
    }
  }
  n = j+1;
  int count = 0, max = 0;
  for (int i = 0; i < n; i++) {
    count = 0;
    if (st[i].a == '0') {
      for (int j = 0; j < min(2*k, n-i); j++) {
        count += st[i+j].b;
      }
      if (count > max) {
        max = count;
      }
      if (i > n-2*k) {
        break;
      }
    } else {
      for (int j = 0; j < min(2*k+1, n-i); j++) {
        count += st[i+j].b;
      }if (count > max) {
        max = count;
      }
      if (i > n-2*k-1) {
        break;
      }
    }
  }
  printf("%d\n", max);
  return 0;
}
