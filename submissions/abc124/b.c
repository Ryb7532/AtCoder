# include <stdio.h>

int main() {
  int n, count = 0, mh = 0, a;
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    if (a >= mh) {
      count++;
      mh = a;
    }
  }
  printf("%d\n", count);
  return 0;
}
