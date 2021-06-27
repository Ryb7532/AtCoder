#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int a[3][3];
  for (int i=0; i<3; i++)
    scanf("%d%d%d", a[i], a[i]+1, a[i]+2);
  int n;
  scanf("%d", &n);
  int b;
  for (int i=0; i<n; i++){
    scanf("%d", &b);
    for (int j=0; j<3; j++)
      for (int k=0; k<3; k++)
        if (a[j][k] == b) a[j][k] = 0;
  }
  bool check = false;
  for (int i=0; i<3; i++) {
    int cnt = 0;
    for (int j=0; j<3; j++) {
      if (a[i][j] == 0) cnt++;
    }
    if (cnt == 3) check = true;
    cnt = 0;
    for (int j=0; j<3; j++) {
      if (a[j][i] == 0) cnt++;
    }
    if (cnt == 3) check = true;
  }
  int cnt = 0;
  for (int i=0; i<3; i++) {
    if (a[i][i] == 0) cnt++;
  }
  if (cnt == 3) check = true;
  cnt = 0;
  for (int i = 0; i < 3; i++)
  {
    if (a[2-i][i] == 0)
      cnt++;
  }
  if (cnt == 3)
    check = true;
  if (check)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
