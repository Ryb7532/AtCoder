#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

typedef struct TV {
  int s;
  int t;
  int c;
} TV;

//チャンネルを昇順（同じ場合開始時間を昇順）
int c_acs(const void *a, const void *b)
{
  if (((TV *)a)->c == ((TV *)b)->c)
    return ((TV *)a)->s - ((TV *)b)->s;
  return ((TV *)a)->c - ((TV *)b)->c;
}

//開始時間を昇順
int s_acs(const void *a, const void *b)
{
  return ((TV *)a)->s - ((TV *)b)->s;
}

int main() {
  int n, c;
  scanf("%d%d", &n, &c);
  TV t[n];
  for (int i=0; i<n; i++)
    scanf("%d%d%d", &(t[i].s), &(t[i].t), &(t[i].c));
  qsort(t, n, sizeof(TV), c_acs);
  int j=0;
  for (int i=1; i<n; i++) {
    if (t[j].c == t[i].c) {
      if (t[j].t == t[i].s) {
        t[j].t = t[i].t;
        t[i].s = 0;
      } else {
        j = i;
      }
    } else {
      j = i;
    }
  }
  //for (int i=0; i<n; i++) printf("%d %d %d\n", t[i].s, t[i].t, t[i].c);
  int recoder[30] = {}, ans = 1;
  bool can;
  qsort(t, n, sizeof(TV), s_acs);
  for (int i=0; i<n; i++) {
    can = false;
    if (t[i].s == 0)
      continue;
    for (int j=0; j<ans; j++) {
      if(recoder[j]<t[i].s) {
        recoder[j] = t[i].t;
        can = true;
        break;
      }
    }
    if (!can) {
      recoder[ans] = t[i].t;
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
