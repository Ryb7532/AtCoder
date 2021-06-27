#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  int t[n+1], x[n+1], y[n+1];
  t[0] = 0; x[0] = 0; y[0] = 0;
  for (int i=1; i<n+1; i++) scanf("%d%d%d", t+i, x+i, y+i);
  bool canTrip = true;
  for (int i=0; i<n; i++) {
    int time = t[i+1] - t[i];
    int dist = x[i+1] + y[i+1] - x[i] - y[i];
    if (time < dist || (time - dist)%2 != 0) {
      canTrip = false;
      break;
    }
  }
  if (canTrip) printf("Yes\n");
  else printf("No\n");
  return 0;
}
