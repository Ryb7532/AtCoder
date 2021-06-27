#include <stdio.h>
#include <stdlib.h>

typedef struct num {
  int idx;
  int cnt;
}num;

int cmp(const void *x, const void *y) {
  return ((num *)y)->cnt - ((num *)x)->cnt;
}

int main() {
  int n, v, ans=0;
  scanf("%d", &n);
  num me[100005], mo[100005];
  for (int i=0; i<100000; i++) {
    me[i].cnt=0; me[i].idx=i;
    mo[i].cnt=0; mo[i].idx=i;
  }
  for (int i=0; i<n; i++) {
    scanf("%d", &v);
    if (i%2==1) me[v-1].cnt++;
    else mo[v-1].cnt++;
  }
  qsort(me, 100000, sizeof(num), cmp);
  qsort(mo, 100000, sizeof(num), cmp);
  if (me[0].idx == mo[0].idx) {
    if (me[1].cnt < mo[1].cnt) ans += n-me[0].cnt-mo[1].cnt;
    else ans += n-me[1].cnt-mo[0].cnt;
  }else ans += n-me[0].cnt-mo[0].cnt;
  printf("%d\n", ans);
  return 0;
}
